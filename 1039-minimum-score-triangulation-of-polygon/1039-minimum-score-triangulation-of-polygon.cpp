class Solution {
public:
    int func(vector<int> &values, int i, int j, vector<vector<int>> &dp)
{
    if (i + 1 == j)
    {
        return 0;
    }

    if(dp[i][j]!=0)return dp[i][j];

    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, ((values[i] * values[k] * values[j]) + func(values, i, k, dp) + func(values, k, j, dp)));
    }
    return dp[i][j]=ans;
}

int minScoreTriangulation(vector<int> &values)
{
    // the intuition is to first tackle it with recursion and then go ahead towards dynamic programming
    int n=values.size();
    vector<vector<int>> dp(n, vector<int> (n));
    return func(values, 0, values.size() - 1, dp);
}
};