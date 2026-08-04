class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        vector<int> rightGreatest(n);
        vector<int> leftGreatest(n);
        for(int i=n-1;i>=0;i--){
            rightGreatest[i] = maxi;
            maxi = max(maxi , nums[i]);
        }
        maxi=0;
        for(int i=0;i<n;i++){
            leftGreatest[i] = maxi;
            maxi = max(maxi , nums[i]);
        }

    
        long long ans =0;
        for(int j=1;j<n-1;j++){
            ans = max(ans, 1LL*(leftGreatest[j] - nums[j])* rightGreatest[j]);
        }
        return ans;
    }
};