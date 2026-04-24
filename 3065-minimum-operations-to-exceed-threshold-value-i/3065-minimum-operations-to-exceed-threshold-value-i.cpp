class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    int n = nums.size();
    int s = 0;
    int e = n-1;
    int ans = n;
    sort(nums.begin(), nums.end());
    while(s<=e){
        int mid = s+(e-s)/2;
        if(nums[mid] >= k){
            ans = mid;
            e = mid-1;
        }else {
            s = mid+1;
        }
    }    
    return ans;   
}
};