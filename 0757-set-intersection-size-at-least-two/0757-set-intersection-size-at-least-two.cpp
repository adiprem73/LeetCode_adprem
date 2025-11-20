class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b){
    if (a[1] != b[1]) return a[1] < b[1];
    return a[0] > b[0];
}

int intersectionSizeTwo(vector<vector<int>> &intervals)
{
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(), cmp);

    set<int> st; // chosen numbers

    // track two largest chosen numbers (s1 <= s2). initialize to impossible values
    int s1 = INT_MIN, s2 = INT_MIN;

    for (auto &itv : intervals) {
        int a = itv[0], b = itv[1];

        // count how many of s1,s2 lie in [a,b]
        int cnt = 0;
        if (s1 >= a && s1 <= b) cnt++;
        if (s2 >= a && s2 <= b) cnt++;

        if (cnt == 2) {
            // already satisfied
            continue;
        } else if (cnt == 1) {
            // need to add one new distinct number inside [a,b]
            // prefer b, but if that equals the existing one, pick b-1
            int existing = (s2 >= a && s2 <= b) ? s2 : s1;
            int pick = b;
            if (pick == existing) pick = b - 1;
            // ensure pick is inside interval
            if (pick < a) pick = a; // fallback (interval length might be 1)
            st.insert(pick);

            // update s1 and s2 to be the two largest in the set
            auto itr = st.end(); itr--;
            s2 = *itr;
            if (itr != st.begin()) { itr--; s1 = *itr; }
            else s1 = s2;
        } else { // cnt == 0
            // need two numbers. choose b-1 and b (rightmost)
            int pick1 = b - 1;
            int pick2 = b;
            if (pick1 < a) {
                // interval too small for b-1; fallback to a and b
                pick1 = a;
            }
            st.insert(pick1);
            st.insert(pick2);

            auto itr = st.end(); itr--;
            s2 = *itr;
            if (itr != st.begin()) { itr--; s1 = *itr; }
            else s1 = s2;
        }
    }

    return (int)st.size();
}
};