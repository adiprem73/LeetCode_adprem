class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // for this problem we will try to implement the property of suffix sum
        int n = nums.size();
        // vector<int> prefix(n);
        int sum = 0;
        unordered_map<int, int> hash; // this is going to store the frequency of
                                      // a certain prefix sum that has come
        hash[0] =1;
        int cnt =0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int target = sum - k;

            if (hash.find(target) != hash.end()) {
                cnt += hash[target];
            }

            hash[sum]++;
            // prefix[i] = sum;
        }
        // if at index i, prefix sum is x
        // for a subarray of sum k, the rest of the sum of the subarray will be
        // x-k
        
        return cnt;
    }
};