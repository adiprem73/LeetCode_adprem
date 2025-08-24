class Solution {
public:
int func(int ind, int target, vector<int> & nums){
    if(ind ==0){
        if(target==0 && nums[0]==0) return 2;

        if(target==nums[0] || target== -nums[0]) return 1;
    }

    if(ind<0)return 0;

    int plus=func(ind-1, target- nums[ind], nums);

    int minus=func(ind-1, target+ nums[ind], nums);

    return plus+minus;
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size();
    return func(n-1, target, nums);
}
};