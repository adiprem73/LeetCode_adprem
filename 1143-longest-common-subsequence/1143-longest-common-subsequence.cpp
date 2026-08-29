class Solution {
public:
    int func(int ind1, int ind2, string& text1, string& text2,
             vector<vector<int>>& dp) {
        // base case
        if (ind1 == text1.size() or ind2 == text2.size()) {
            return 0;
        }

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        int same = 0, diff = 0;
        // same
        if (text1[ind1] == text2[ind2]) {
            same = 1 + func(ind1 + 1, ind2 + 1, text1, text2, dp);
        } else {
            diff = max(func(ind1 + 1, ind2, text1, text2, dp),
                       func(ind1, ind2 + 1, text1, text2, dp));
        }

        return dp[ind1][ind2] = same + diff;
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1,
                               vector<int>(text2.size() + 1, 0));

        for (int ind1 = text1.size()-1; ind1>=0; ind1--) {
            for (int ind2 = text2.size()-1; ind2 >=0; ind2--) {
                int same = 0, diff = 0;
                // same
                if (text1[ind1] == text2[ind2]) {
                    same = 1 + dp[ind1+1][ind2+1];
                } else {
                    diff = max(dp[ind1+1][ind2], dp[ind1][ind2+1]);
                }

                dp[ind1][ind2] = same+diff;
            }
        }

        return dp[0][0];
    }
};