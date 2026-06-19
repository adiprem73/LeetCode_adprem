class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mx=0;

        int mn=INT_MAX;
        for(auto it: nums){
            mx=max(mx, it);
            mn= min(mn, it);
        }

        long long ans = 1LL*(mx-mn)*k;
        return ans;
    }
};