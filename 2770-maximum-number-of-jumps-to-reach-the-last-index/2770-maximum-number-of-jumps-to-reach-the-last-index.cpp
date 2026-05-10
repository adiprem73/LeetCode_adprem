class Solution {
public:
    int func(int pos, vector<int> &nums,
         int target, vector<int> &dp)
{
    int n = nums.size();

    if (pos == n - 1)
    {
        return 0;
    }

    if (dp[pos] != -2)
    {
        return dp[pos];
    }

    int ans = -1;

    for (int next = pos + 1; next < n; next++)
    {
        if (abs(nums[pos] - nums[next]) <= target)
        {
            int jump = func(next, nums, target, dp);

            if (jump != -1)
            {
                ans = max(ans, 1 + jump);
            }
        }
    }

    return dp[pos] = ans;
}

int maximumJumps(vector<int> &nums, int target)
{
    vector<int> dp(nums.size(), -2);

    return func(0, nums, target, dp);
}
};