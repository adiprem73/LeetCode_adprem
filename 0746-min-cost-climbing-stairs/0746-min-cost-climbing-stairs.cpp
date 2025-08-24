class Solution {
public:
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n,-1);
    
    dp[0] = cost[0];
    dp[1] = cost[1];
    
    for(int i=2;i<n;i++){
        int oneStep= dp[i-1];
        int twoStep= dp[i-2];

        dp[i]= cost[i] + min(oneStep, twoStep);
    }
    return min(dp[n-1], dp[n-2]);
}
};