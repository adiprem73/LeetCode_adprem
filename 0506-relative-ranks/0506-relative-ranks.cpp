class Solution {
public:
    vector<string> findRelativeRanks(vector<int> &score)
{
    int n = score.size();
    vector<int> temp = score;
    sort(score.begin(), score.end());
    reverse(score.begin(), score.end());
    map<int, string> mp;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            mp[score[i]] = "Gold Medal";
        }
        else if (i == 1)
        {
            mp[score[i]] = "Silver Medal";
        }
        else if (i == 2)
        {
            mp[score[i]] = "Bronze Medal";
        }
        else
        {
            mp[score[i]] = to_string(i + 1);
        }
    }
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(mp[temp[i]]);
}
return ans;
}
};