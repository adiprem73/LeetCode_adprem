class Solution {
public:
    vector<int> intersection(vector<vector<int>> &nums)
{
    vector<int> freq(1001,0);
    for (int i = 0; i < nums[0].size(); i++)
    {
        freq[nums[0][i]]++;
    }
    for (int i = 1; i < nums.size(); i++)
    {
        vector<int> seen(1001,0);
        for (int j = 0; j < nums[i].size(); j++)
        {
            if (freq[nums[i][j]])
            {
                seen[nums[i][j]]=1;
            }
        }
        freq=seen;
        // vprint(freq);
    }
    vector<int> ans;
    for (int i = 0; i < freq.size(); i++)
    {
        if (freq[i] != 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
};