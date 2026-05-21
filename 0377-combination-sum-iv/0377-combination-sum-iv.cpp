class Solution {
public:
   int func(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    // base case
    if(target==0){
        return 1;
    }
    if(target<0 || ind>=nums.size()){
        return 0;
    }

    if(dp[ind][target] !=-1)return dp[ind][target];
    // pick and move to index 0
    int pick = func(0, target-nums[ind], nums, dp);
    // not pick and continue
    int notPick = func(ind+1, target, nums, dp);

    return dp[ind][target] = pick + notPick;
}

int combinationSum4(vector<int>& nums, int target) {
    // int ans = func(0, target, nums);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(target+1,-1));
    int ans = func(0, target, nums, dp);
    return ans;
}
};