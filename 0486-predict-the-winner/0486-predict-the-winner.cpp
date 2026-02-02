class Solution {
public:
    int solve(vector<int>& nums, int l, int r){
    if(l==r){
        return nums[l];
    }

    int pickLeft = nums[l] - solve(nums, l+1, r);
    int pickRight = nums[r] - solve(nums, l, r-1);
    return max(pickLeft, pickRight);
}



bool predictTheWinner(vector<int>& nums) {
    return solve(nums, 0, nums.size()-1) >= 0;
}
};