class Solution {
public:
    int minOperations(vector<int>& nums) {
    int cnt =0;
    int n = nums.size();
    for(int i=0;i<n-3+1;i++){
        if(nums[i] == 0){
            nums[i] = 1-nums[i];
            nums[i + 1] = 1 - nums[i + 1];
            nums[i+2] = 1 - nums[i+2];
            cnt++;
        }
    }
    for(auto it: nums){
        if(it == 0){
            return -1;
        }
    }
    return cnt;
}
};