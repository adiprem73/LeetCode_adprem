class Solution {
public:
    static const int INF = 1e9;
    int func(int ind, string &source, string &target, vector<vector<string>> &rules, vector<int> &costs, vector<int>& dp)
{
    int n = source.length();
    // base case
    if (ind >= n)
    {
        return 0;
    }
    int ans = INF;

    if(dp[ind] != -1){
        return dp[ind];
    }

    int costAheadSkipping = 1e9, costAhead = 1e9;
    if (source[ind] == target[ind])
        ans = min(ans, func(ind + 1, source, target, rules, costs, dp));

    for (int i = 0; i < rules.size(); i++)
    {
        int ruleLength = rules[i][0].length();
        bool matched = true;
        int costFromStars = 0;
        if (ind + ruleLength > n)
            continue;

        for (int j = 0; j < ruleLength; j++)
        {
            if (source[ind + j] == rules[i][0][j] || rules[i][0][j] == '*')
            {
                if (rules[i][0][j] == '*')
                    costFromStars++;
            }
            else
            {
                matched = false;
                break;
            }
        }
        if (!matched)
            continue;

        // now since the rule's string has matched with the ind starting in the soruce, we wil have two options, bear the cost and do the change and skip the change
        // do the change
        matched = true;
        for (int j = 0; j < ruleLength; j++)
        {
            if (rules[i][1][j] != target[ind + j])
            {
                matched = false;
                break;
            }
        }

        if (!matched)
            continue;

        ans = min(ans,
                  costs[i] + costFromStars +
                      func(ind + ruleLength, source, target, rules, costs, dp));
    }
    return dp[ind] = ans;
}

int minCost(string source, string target, vector<vector<string>> &rules, vector<int> &costs)
{
    int n = source.size();
    vector<int> dp(n, -1);
    int ans = func(0, source, target, rules, costs, dp);
    return (ans>=INF ? -1: ans);
}
};