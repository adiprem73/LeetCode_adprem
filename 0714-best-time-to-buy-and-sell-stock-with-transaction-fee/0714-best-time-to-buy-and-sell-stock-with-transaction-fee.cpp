class Solution {
public:
int func(int ind, int buy, vector<int>& prices, int n, int fee , vector<vector<int>>& dp){
    if(ind == n)return 0;
    if(dp[ind][buy]!=-1)return dp[ind][buy];
    if(buy){
        return dp[ind][buy]=max(-prices[ind]+func(ind+1, 0, prices, n, fee,dp) , func(ind+1, 1, prices, n, fee,dp));
    }
    else{
        return dp[ind][buy]=max( prices[ind]-fee+func(ind +1, 1, prices, n, fee,dp) , func(ind+1, 0, prices, n, fee,dp));
    }
}

int maxProfit(vector<int>& prices, int fee) {
    int n=prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return func(0, 1, prices, n, fee, dp);
}
};