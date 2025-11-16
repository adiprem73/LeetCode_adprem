class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> nums1(n);
        vector<int> nums2(n);
        for(int i=0;i<n;i++){
            nums1[i]= nums[i];
        }
        for(int i=n;i<2*n;i++){
            nums2[i-n]= nums[i];
        }
        vector<int> ans(2*n);
        int a=0;
        int b=0;
        for(int i=0;i<2*n;i++){
            if(i%2==0){
                ans[i]= nums1[a];
                a++;
            }else{
                ans[i]= nums2[b];
                b++;
            }
        }
        return ans;
    }
};