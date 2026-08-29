class Solution {
public:
    int func(int ind, int amountLeft, vector<int>& coins, vector<vector<int>>& dp){
        int n = coins.size();
        // base case
        
        if(ind == n){
            if(amountLeft == 0)return 0;
            else return 1e7;
        }

        if(dp[ind][amountLeft] != -1)return dp[ind][amountLeft];
        int pick=1e7, notPick=1e7;

        if(amountLeft >= coins[ind]){
            pick = 1 + func(ind, amountLeft-coins[ind], coins, dp);
        }        

        notPick = func(ind+1, amountLeft, coins, dp);

        return dp[ind][amountLeft] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return func(0, amount, coins, dp)==1e7? -1: func(0, amount, coins, dp);
    }
};