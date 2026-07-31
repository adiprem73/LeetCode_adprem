class Solution {
public:
static const int INF = 1e9;

// minimum number of coins required to make up the 'amount' by using coins up untill that index
int func(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    // base case
    int n = coins.size();
    if(ind ==  n){
        if(amount == 0)return 0; // doubt
        return INF;
    }

    // dp base case
    if(dp[ind][amount] != -1){
        return dp[ind][amount];
    }

    // for every index we have like two options, one is to take the element from that index and stay there... and the other is to just move ahead without taking
    int pick = INF;
    if(coins[ind]<=amount){
        pick = func(ind, amount - coins[ind], coins, dp) + 1;
    }

    int notPick = func(ind + 1, amount, coins, dp);

    return dp[ind][amount] = min(pick, notPick);
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = func(0, amount, coins, dp);
    
    if (ans == INF)
        return -1;
    return ans;
}
};