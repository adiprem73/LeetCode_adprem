class Solution {
public:
    bool isIsomorphic(string s, string t) {
    map<char,int> mp1,mp2;
    for(int i=0;i<s.size();i++){
        mp1[s[i]]=i;
    }
    for(int i=0;i<t.size();i++){
        mp2[t[i]]=i;
    }
    bool flag=true;
    for(int i=0;i<s.length();i++){
        char ch1=s[i];
        char ch2=t[i];
        if(mp1[ch1]!=mp2[ch2]){
            flag=false;
            break;
        }
    }
    return flag;
};
}