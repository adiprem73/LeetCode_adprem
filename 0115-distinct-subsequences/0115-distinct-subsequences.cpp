class Solution {
public:
    int func(int ps, int pt, string s, string t, vector<vector<int>>& dp){
        // base case
        if(pt<0){
            return 1;
        }
        if(ps<0){
            return 0;
        }

        if(dp[ps][pt]!=-1)return dp[ps][pt];

        int same=0, diff=0, notMatch=0;
        if(s[ps] == t[pt]){
            same = func(ps-1, pt-1, s, t, dp) + func(ps-1, pt, s, t, dp);
        }
        else{
            diff = func(ps-1, pt, s, t, dp);
        }
        

        return dp[ps][pt] = same + diff;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));

        return func(s.size()-1,t.size()-1,s,t, dp);
    }
};