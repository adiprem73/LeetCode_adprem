class Solution {
public:
    int func(int ind, int amount, vector<int> &coins, vector<vector<int>>& dp)
{
    // base case
    int n = coins.size();
    if(ind >= n){
        if(amount == 0 )return 1;
        return 0;
    }

    // dp check
    if(dp[ind][amount] != -1){
        return dp[ind][amount];
    }

    int take = 0;
    // this is a knapsack problem. we will just (take and stay) and (not take and move ahead) our way through this problem
    int notTake = func(ind+1, amount, coins, dp);
    if(coins[ind]<=amount){
        take = func(ind, amount-coins[ind], coins, dp);
    }
    return dp[ind][amount] = take + notTake;
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    return func(0, amount, coins, dp);
}
};