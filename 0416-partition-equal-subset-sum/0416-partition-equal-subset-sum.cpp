class Solution {
public:
    bool func(int ind, int curSum, int totalSum, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();

        // base case
        if(ind>=n)return false;
        if(curSum*2 == totalSum)return true;

        // dp case
        if(dp[ind][curSum]!=-1)return dp[ind][curSum];

        bool pick=false, notPick = false;
        pick = func(ind+1, curSum + nums[ind] , totalSum, nums, dp);

        notPick = func(ind+1, curSum , totalSum, nums, dp);

        return dp[ind][curSum] =  pick || notPick;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return func(0, 0, sum, nums, dp);
    }
};