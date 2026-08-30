class Solution {
public:
    int characterReplacement(string s, int k)
{
    int l = 0;
    int r = 0;
    int maxFreq = 0;
    int maxLen = 0;
    map<char, int> mp;
    while (r < s.length())
    {
        mp[s[r]]++;
        maxFreq = max(maxFreq, mp[s[r]]);

        // If the number of characters to change is more than k, shrink window
        while ((r - l + 1) - maxFreq > k)
        {
            mp[s[l]]--;
            l++;
        }

        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}
};