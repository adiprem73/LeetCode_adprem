class Solution {
public:
    int climbingstairs(int ind, vector<int> & dp){
    if(ind<=1)return 1;

    if(dp[ind]!=-1){
        return dp[ind];
    }

    return dp[ind]= climbingstairs(ind-1, dp)+ climbingstairs(ind-2, dp);
}

int climbStairs(int n) {
    vector<int> dp(n+1,-1);
    int ans= climbingstairs(n,dp);
    return ans;
}
};