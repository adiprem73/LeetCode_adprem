class Solution {
public:
int func(int ind, int amount, vector<int> &coins, vector<vector<int>>& dp)
{
    // base case
    if (amount == 0)
        return 1;
    if (ind < 0)
        return 0;
    if (amount < 0)
        return 0;

    if(dp[ind][amount]!=-1)return dp[ind][amount];
    int notPick = func(ind - 1, amount, coins, dp);
    int pick = 0;
    if (coins[ind] <= amount)
    {
        pick = func(ind, amount - coins[ind], coins, dp);
    }
    return dp[ind][amount]=pick + notPick;
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (amount+1, -1));
    return func(n - 1, amount, coins, dp);
}
};