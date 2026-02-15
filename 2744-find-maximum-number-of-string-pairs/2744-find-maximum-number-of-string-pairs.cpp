class Solution {
public:
    int maximumNumberOfStringPairs(vector<string> &words)
{
    unordered_map<string, int> mp;
    for (auto it : words)
    {
        mp[it]++;
    }
    int cnt = 0;
    for (string s : words)
    {
        string r = s;
        reverse(r.begin(), r.end());
        if (mp[r] > 0)
        {
            if(s==r){
                if(mp[r]>=2){
                    mp[s]-=2;
                    cnt++;
                }
            }else {
                mp[s]--;
                mp[r]--;
                cnt++;
            }
        }
        // mprint(mp);
    }
    return cnt;
}
};