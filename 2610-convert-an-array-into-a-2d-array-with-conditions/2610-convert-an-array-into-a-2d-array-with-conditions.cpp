class Solution {
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (auto it : nums)
    {
        mp[it]++;
    }
    int mark = nums.size();
    vector<vector<int>> ans;
    while (mark > 0)
    {
        vector<int> curr;
        for (auto &it : mp)
        {
            if (it.second > 0)
            {
                curr.push_back(it.first);
                it.second--;
                mark--;
            }
        }
        ans.push_back(curr);
    }
    return ans;
}
};