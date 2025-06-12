class Solution {
public:
int lengthOfLongestSubstring(string s) {
    int l=0,r=0;
    int maxLen=0;
    int len=0;
    map<char,int> mp;
    while(r<s.length()){
        
        if(mp.find(s[r])!=mp.end()){
            l=max(l,mp[s[r]]+1);
        }

        mp[s[r]]=r;

        len=r-l+1;
        maxLen=max(len,maxLen);

        // cout<<"r: "<<r<<" l: "<<l<<" len: "<<len<<" maxlen: "<<maxLen<<endl;
        r++;
    }
    return maxLen;
}
};