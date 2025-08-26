class Solution {
public:
    int func(int ind, int prevInd, vector<int> &nums, int n, vector<vector<int>> &dp)
{
    // base case
    if (ind == n)
        return 0;

    if(dp[ind][prevInd+1]!=-1)return dp[ind][prevInd+1];

    int notTake = func(ind + 1, prevInd, nums, n,dp);

    int take = 0;
    if (prevInd == -1 || nums[prevInd] < nums[ind])
    {
        take = func(ind + 1, ind, nums, n,dp) + 1;
    }
    return dp[ind][prevInd+1]=max(take, notTake);
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n+1,-1));
    return func(0, -1, nums, n, dp);
}
};