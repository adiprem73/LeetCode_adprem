class Solution {
public:
    int func(int ind, int target, vector<int>& nums){
    int n = nums.size();
    // base case
    if(ind == n){
        if(target == 0)return 1;
        return 0;
    }


    // additon 
    int add = func(ind+1, target-nums[ind], nums);

    // subtraction
    int sub = func(ind+1, target+nums[ind], nums);

    return add + sub;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    return func(0, target, nums);
}
};