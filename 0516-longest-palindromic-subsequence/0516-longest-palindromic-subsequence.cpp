class Solution {
public:
    int lcs(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp) {
        // base case
        if (ind1 >= s1.size() || ind2 >= s2.size()) {
            return 0;
        }
        // dp case
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        int same = 0, diff = 0;
        if (s1[ind1] == s2[ind2]) {
            same = 1 + lcs(ind1 + 1, ind2 + 1, s1, s2, dp);
        } else {
            diff = max(lcs(ind1 + 1, ind2, s1, s2, dp),
                       lcs(ind1, ind2 + 1, s1, s2, dp));
        }
        return dp[ind1][ind2] = same + diff;
    }

    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));

        int n = s.size();
        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= n; ind2++) {
                int same = 0, diff = 0;
                if (s[ind1-1] == s2[ind2-1]) {
                    dp[ind1][ind2] =1 + dp[ind1-1][ind2-1];
                } else {
                    dp[ind1][ind2] = max(dp[ind1-1][ind2],
                               dp[ind1][ind2-1]);
                }
            }
        }

        return dp[n][n];
    }
};