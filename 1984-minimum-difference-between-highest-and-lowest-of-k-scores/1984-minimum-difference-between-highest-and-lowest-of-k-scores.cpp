class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    if(k==1){
        return 0;
    }
    int ans= INT_MAX;
    for(int i=0;i+k-1<nums.size();i++){
        // cout<<nums[i]<<" "<<nums[i+k-1]<<endl;
        ans = min(ans, abs(nums[i]- nums[i+k-1]));
    }
    return ans;
}
};