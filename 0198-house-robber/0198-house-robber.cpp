class Solution {
public:
    int func(int ind, vector<int>& nums, vector<int> &dp){
        // base case
        int n = nums.size();
        if(ind >= n)return 0;

        if(dp[ind]!= -1)return dp[ind];

        // rob current house
        int robCurrentHouse = nums[ind]+ func(ind+2, nums, dp);

        // skip current house
        int skipCurrentHouse = func(ind+1, nums, dp);

        return dp[ind] = max(robCurrentHouse, skipCurrentHouse);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return func(0, nums, dp);
    }
};