class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> mp;
        int r = 0, ans = 0;

        for(int l = 0; l < s.size(); l++) {
            mp[s[l]]++;

            while(mp[s[l]] > 2) {
                mp[s[r]]--;
                r++;
            }

            ans = max(ans, l - r + 1);
        }

        return ans;
    }
};