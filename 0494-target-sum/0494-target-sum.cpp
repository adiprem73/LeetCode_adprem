class Solution {
public:
int func(int ind, int target, vector<int> & nums, vector<vector<int>> &dp, int totalSum){
    if(ind ==0){
        if(target==0 && nums[0]==0) return 2;

        if(target==nums[0] || target== -nums[0]) return 1;
        return 0;
    }

    if(abs(target) > totalSum) return 0;


    if(dp[ind][target +totalSum]!= -1)return dp[ind][target+totalSum];

    int plus=func(ind-1, target- nums[ind], nums, dp, totalSum);

    int minus=func(ind-1, target+ nums[ind], nums, dp, totalSum);
    return dp[ind][target+totalSum]=plus+minus;
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size();
    int totalSum=accumulate(nums.begin(), nums.end(),0);

    vector<vector<int>> dp(n, vector<int>(2* totalSum + 1, -1));
    return func(n-1, target, nums, dp, totalSum);
}
};