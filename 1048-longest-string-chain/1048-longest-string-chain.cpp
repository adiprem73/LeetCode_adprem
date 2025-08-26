class Solution {
public:
    bool compare(string &s1, string &s2)
{
    int n = s1.length();
    int m = s2.length();

    if (n - m != 1)
        return false;

    int i = 0, j = 0;
    while (i < n)
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if (i == n && j == m)
        return true;
    return false;
}

int longestStrChain(vector<string> &words)
{
    int maxi = INT_MIN;
    int n = words.size();
    sort(words.begin(), words.end(), [](const string &a, const string &b)
         { return a.length() < b.length(); });

    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (compare(words[i], words[prev]) && dp[i] < 1 + dp[prev])
            {
                dp[i] = 1 + dp[prev];
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
        }
    }
    return maxi;
}
};