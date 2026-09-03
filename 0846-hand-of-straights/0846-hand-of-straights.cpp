class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        for (auto it : hand) {
            mp[it]++;
        }
        for (auto& it : mp) {
            while (it.second > 0) {
                for (int i = 0; i < groupSize; i++) {
                    if (mp.find(it.first + i) == mp.end())
                        return false;
                    if (mp[it.first + i] == 0)
                        return false;
                    else
                        mp[it.first + i]--;
                    // if(mp[it.first+i] == 0)mp.erase(it.first+i);
                }
            }
        }
        return true;
    }
};