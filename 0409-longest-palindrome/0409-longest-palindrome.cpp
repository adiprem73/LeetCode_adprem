class Solution {
public:
   int getIndex(char ch){
    if(ch>='a' && ch<='z'){
        // cout<<"testt";
        return ch-'a';
    }
    if(ch>='A' && ch<='Z'){
        // cout<<"test";
        return ch-'A'+26;
    }
    return -1;
}

int longestPalindrome(string s)
{
    // mkaing the hash table
    vector<int> hash(52, 0);
    // transform(s.begin(), s.end(), s.begin(), ::tolower);
    for (char c : s)
    {
        hash[getIndex(c)]++;
    }
    int ans = 0;
    int mxOdd = -1;
    vector<int> odd;
    bool flag= false;
    for (auto freq : hash)
    {
        if (freq % 2 == 0)
        {
            ans += freq;
        }
        else
        {
            flag = true;
            ans+=freq-1;
        }
    }
    if(flag){
        ans++;
    }
    // if (mxOdd != -1)
    // {
    //     ans += mxOdd;
    // }
    return ans;
}
};