

struct PacketKey {
    int s, d, t;
    bool operator==(PacketKey const& o) const noexcept {
        return s==o.s && d==o.d && t==o.t;
    }
};

struct PacketKeyHash {
    size_t operator()(PacketKey const& k) const noexcept {
        // combine 3 ints with a standard mix
        size_t h = std::hash<int>()(k.s);
        h ^= std::hash<int>()(k.d) + 0x9e3779b97f4a7c15ULL + (h<<6) + (h>>2);
        h ^= std::hash<int>()(k.t) + 0x9e3779b97f4a7c15ULL + (h<<6) + (h>>2);
        return h;
    }
};

class Router {
private:
    int memLimit;
    queue<array<int,3>> q;                                        // FIFO store of packets
    unordered_set<PacketKey, PacketKeyHash> st;                   // membership for duplicates
    unordered_map<int, deque<int>> dstTimestamps;                 // destination -> deque of timestamps (sorted)

    // helper to evict oldest packet (assumes q not empty)
    void evictOldest() {
        auto arr = q.front(); q.pop();
        PacketKey key{arr[0], arr[1], arr[2]};
        st.erase(key);
        auto it = dstTimestamps.find(arr[1]);
        if (it != dstTimestamps.end()) {
            // since timestamps appended in increasing order and we evict oldest globally,
            // the timestamp to remove must be at front of that destination's deque
            if (!it->second.empty() && it->second.front() == arr[2]) {
                it->second.pop_front();
            } else {
                // In theory this shouldn't happen due to ordering guarantees.
                // But to be robust, find & erase (rare).
                auto &dq = it->second;
                for (auto iter = dq.begin(); iter != dq.end(); ++iter) {
                    if (*iter == arr[2]) { dq.erase(iter); break; }
                }
            }
            if (it->second.empty()) dstTimestamps.erase(it);
        }
    }

public:
    Router(int memoryLimit) : memLimit(memoryLimit) {
        // memLimit per constraints >= 2, but safe guard
        if (memLimit < 0) memLimit = 0;
        st.reserve((size_t)min(100000, max(1, memLimit*2))); // reduce rehashes
    }

    bool addPacket(int source, int destination, int timestamp) {
        PacketKey key{source, destination, timestamp};
        if (st.count(key)) return false;

        // if full then evict oldest first
        if ((int)st.size() >= memLimit) {
            if (!q.empty()) evictOldest();
            else return false; // memLimit==0 or weird state
        }

        // insert
        q.push({source, destination, timestamp});
        st.insert(key);
        // timestamps come in non-decreasing order, so push_back keeps deque sorted
        dstTimestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto arr = q.front(); q.pop();
        PacketKey key{arr[0], arr[1], arr[2]};
        st.erase(key);

        auto it = dstTimestamps.find(arr[1]);
        if (it != dstTimestamps.end()) {
            if (!it->second.empty() && it->second.front() == arr[2]) {
                it->second.pop_front();
            } else {
                // robust fallback (shouldn't be needed)
                auto &dq = it->second;
                for (auto iter = dq.begin(); iter != dq.end(); ++iter) {
                    if (*iter == arr[2]) { dq.erase(iter); break; }
                }
            }
            if (it->second.empty()) dstTimestamps.erase(it);
        }

        return {arr[0], arr[1], arr[2]};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = dstTimestamps.find(destination);
        if (it == dstTimestamps.end()) return 0;
        auto &dq = it->second;
        // deque has random access iterators; lower_bound/upper_bound work in O(log n)
        auto lo = lower_bound(dq.begin(), dq.end(), startTime);
        auto hi = upper_bound(dq.begin(), dq.end(), endTime);
        return (int)distance(lo, hi);
    }
};