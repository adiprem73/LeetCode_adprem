class Solution {
public:
    int func(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp){
        // base case
        if(ind1 == text1.size() or ind2 == text2.size()){
            return 0;
        }

        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

        int same =0, diff=0;
        // same
        if(text1[ind1]==text2[ind2]){
            same = 1+func(ind1+1, ind2+1, text1, text2, dp);
        }
        else{
            diff = max(func(ind1+1, ind2, text1, text2, dp),func(ind1, ind2+1, text1, text2, dp));

        }

        return dp[ind1][ind2]= same+diff;
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(), vector<int>(text2.size(), -1));
        return func(0, 0, text1, text2, dp);
    }
};