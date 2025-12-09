class Solution {
public:
    int specialTriplets(vector<int> &nums) {
        const int MOD = 1'000'000'007;
        long long cnt = 0;
        int n = nums.size();

        // freq maps for left and right
        unordered_map<long long, long long> left, right;

        for (int x : nums) {
            right[x]++;
        }

        for (int j = 0; j < n; j++) {
            // current element middle ban raha hai, isliye right se hatao
            right[nums[j]]--;

            if (j > 0 && j < n - 1) {
                long long val = 2LL * nums[j];

                long long leftCount  = left[val];
                long long rightCount = right[val];

                // yaha mod use karo
                long long add = (leftCount % MOD) * (rightCount % MOD) % MOD;
                cnt = (cnt + add) % MOD;
            }

            // ab ye element future ke liye left me chala jayega
            left[nums[j]]++;
        }

        return (int)(cnt % MOD);
    }

};