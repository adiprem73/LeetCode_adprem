class Solution {
public:
    bool simulCheck(vector<int> nums, int threshold, int div){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        int q = nums[i]/div;
        if(nums[i]%div)q+=1;
        sum+=q;
    }
    return sum<=threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    int s=1;
    int maxi= INT_MIN;
    for(int i=0;i<n;i++){
        maxi = max(maxi, nums[i]);
    }
    int e = maxi;
    int ans = INT_MAX;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(simulCheck(nums, threshold, mid)){
            ans = min(ans, mid);
            e=mid-1;
        }else{
            s= mid+1;
        }
    }
    return ans;
}
};