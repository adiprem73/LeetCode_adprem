class Solution {
 public:
  int magicalSum(int m, int k, vector<int>& nums) {
    const vector<vector<int>> comb = getComb(m, m);
    vector<vector<vector<vector<int>>>> mem(
        m + 1, vector<vector<vector<int>>>(
                   k + 1, vector<vector<int>>(nums.size() + 1,
                                              vector<int>(m + 1, -1))));
    return dp(m, k, 0, 0, nums, mem, comb);
  }

 private:
  static constexpr int MOD = 1'000'000'007;
  int dp(int m, int k, int i, unsigned carry, const vector<int>& nums,
         vector<vector<vector<vector<int>>>>& mem,
         const vector<vector<int>>& comb) {
    if (m < 0 || k < 0 || (m + __builtin_popcount(carry) < k)) return 0;
    if (m == 0) return k == __builtin_popcount(carry) ? 1 : 0;
    if (i == (int)nums.size()) return 0;
    if (mem[m][k][i][carry] != -1) return mem[m][k][i][carry];
    long res = 0;
    for (int count = 0; count <= m; ++count) {
      long contribution = 1LL * comb[m][count] * modPow(nums[i], count) % MOD;
      unsigned newCarry = carry + (unsigned)count;
      // next k reduced by current bit (newCarry % 2), carry shifts right
      res = (res + 1LL * dp(m - count, k - (newCarry & 1), i + 1,
                           newCarry >> 1, nums, mem, comb) * contribution) %
            MOD;
    }
    mem[m][k][i][carry] = (int)res;
    return mem[m][k][i][carry];
  }

  vector<vector<int>> getComb(int n, int k) {
    vector<vector<int>> comb(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; ++i) comb[i][0] = 1;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= k; ++j)
        comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
    return comb;
  }

  long modPow(long x, long n) {
    long res = 1;
    x %= MOD;
    while (n > 0) {
      if (n & 1) res = (res * x) % MOD;
      x = (x * x) % MOD;
      n >>= 1;
    }
    return res;
  }
};