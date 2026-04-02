class Solution {
public:
    int dfs(int r, int c, int neut, vector<vector<int>> &coins, vector<vector<vector<int>>> &dp)
{
    int m = coins.size();
    int n = coins[0].size();

    if (r >= m || c >= n)
        return INT_MIN;

    if (r == m - 1 && c == n - 1)
    {
        if (coins[r][c] < 0 && neut > 0)
            return 0;
        return coins[r][c];
    }

    if (dp[r][c][neut] != INT_MIN)
        return dp[r][c][neut];

    int res = INT_MIN;

    if (coins[r][c] >= 0)
    {
        int next = max(
            dfs(r + 1, c, neut, coins, dp),
            dfs(r, c + 1, neut, coins, dp));

        if (next != INT_MIN)
            res = coins[r][c] + next;
    }
    else
    {
        // neutralize
        if (neut > 0)
        {
            res = max(res, max(
                               dfs(r + 1, c, neut - 1, coins, dp),
                               dfs(r, c + 1, neut - 1, coins, dp)));
        }

        // take loss
        int next = max(
            dfs(r + 1, c, neut, coins, dp),
            dfs(r, c + 1, neut, coins, dp));

        if (next != INT_MIN)
            res = max(res, coins[r][c] + next);
    }

    return dp[r][c][neut] = res;
}

int maximumAmount(vector<vector<int>> &coins)
{
    int m = coins.size();
    int n = coins[0].size();
    int ans = INT_MIN;
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
    return dfs(0, 0, 2, coins, dp);
}
};