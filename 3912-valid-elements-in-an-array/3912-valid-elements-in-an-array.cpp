class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        if(n==1){
            return nums;
        }
        vector<int> left(n), right(n);
        for(int i=0;i<n;i++){
            left[i] = mx;
            mx = max(mx, nums[i]);
        }
        mx = nums[n-1];
        // cout<<"max : "<<mx<<endl;
        for(int i=n-1;i>=0;i--){
            right[i] = mx;
            mx = max(mx, nums[i]);
        }

        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n-1;i++){
            if(nums[i]>left[i] || nums[i]>right[i]){
                ans.push_back(nums[i]);
            }
        }
        ans.push_back(nums[n-1]);
        return ans;
    }
};