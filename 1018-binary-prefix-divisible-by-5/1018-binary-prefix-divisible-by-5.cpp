class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n);
        int cur = 0;  // will store prefix value mod 5

        for (int i = 0; i < n; i++) {
            cur = (cur * 2 + nums[i]) % 5; // update prefix
            ans[i] = (cur == 0);           // divisible by 5?
        }

        return ans;
    }
};