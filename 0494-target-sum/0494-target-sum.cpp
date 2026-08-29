class Solution {
public:
    int func(int ind, int target, vector<int>& nums){
        // base case
        int n = nums.size();
        if(ind==n){
            if(target ==0)return 1;
            else return 0;
        }

        int add=0, sub=0;

        add = func(ind+1, target- nums[ind], nums);
        
        sub = func(ind+1, target + nums[ind], nums);

        return add+sub;
        
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return func(0, target, nums);
    }
};