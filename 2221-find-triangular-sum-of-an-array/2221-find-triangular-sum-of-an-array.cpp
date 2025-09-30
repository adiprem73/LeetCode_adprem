class Solution {
public:
    int triangularSum(vector<int>& nums) {
    int n=nums.size();
    int k=n;
    while(k>=0){
        for(int i=n-1;i>=n-k+1;i--){
            nums[i]=(nums[i]+nums[i-1])%10;
        }
        k--;
        // vprint(nums);
    }   
    return nums[n-1];   
}
};