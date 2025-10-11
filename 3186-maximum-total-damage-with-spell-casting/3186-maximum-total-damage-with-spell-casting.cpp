class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        if (power.empty()) return 0LL;

        // Aggregate total damage per distinct value
        unordered_map<long long,long long> total;
        total.reserve(power.size()*2);
        for (int v : power) total[v] += v; // each occurrence contributes v damage

        // Sorted distinct values
        vector<long long> vals;
        vals.reserve(total.size());
        for (auto &p : total) vals.push_back(p.first);
        sort(vals.begin(), vals.end());

        int m = vals.size();
        vector<long long> sums(m);
        for (int i = 0; i < m; ++i) sums[i] = total[vals[i]];

        // dp[i] = best using values up to index i (inclusive)
        vector<long long> dp(m, 0);
        for (int i = 0; i < m; ++i) {
            long long skip = (i > 0 ? dp[i-1] : 0LL);

            // find largest index j < i with vals[j] <= vals[i] - 3
            long long need = vals[i] - 3;
            int j = -1;
            if (i > 0) {
                auto it = upper_bound(vals.begin(), vals.begin() + i, need);
                if (it != vals.begin()) {
                    --it;
                    j = int(it - vals.begin());
                }
            }
            long long take = sums[i] + (j >= 0 ? dp[j] : 0LL);

            dp[i] = max(skip, take);
        }

        return dp.back();
    }
};