class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k =0;
        for(auto it: nums){
            if(it == 1){
                k++;
            }
        }
        int cnt1=0;
        for(int i=0;i<k;i++){
            if(nums[i] == 1)cnt1++;
        }
        int mx = cnt1;
        for(int i=k;i<2*n;i++){
            if(nums[(i-k)%n] == 1)cnt1--;
            if(nums[i%n] == 1)cnt1++;
            mx = max(mx, cnt1);
        }
        return k-mx;
    }
};