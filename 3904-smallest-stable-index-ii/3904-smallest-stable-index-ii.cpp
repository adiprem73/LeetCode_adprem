class Solution {
public:
    int firstStableIndex(vector<int> &nums, int k)
{
    vector<int> mx;
    vector<int> mn;
    int n = nums.size();
    int m = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        m = max(m, nums[i]);
        mx.push_back(m);
    }
    m = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        m = min(m, nums[i]);
        mn.push_back(m);
    }
    reverse(mn.begin(), mn.end());

    // vprint(mx);
    // vprint(mn);
    for (int i = 0; i < n; i++)
    {
        if (mx[i] - mn[i] <= k)
        {
            return i;
        }
    }
    return -1;
}
};