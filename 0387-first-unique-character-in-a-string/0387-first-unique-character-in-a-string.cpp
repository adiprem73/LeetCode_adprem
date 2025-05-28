class Solution {
public:
    int firstUniqChar(string s) {
    unordered_map<char,int> mp;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }
    // mprint(mp);
    char ch;
    for(int i=0;i<s.length();i++){
        if(mp[s[i]]==1){
            return i;
            break;
        }
    }  
    return -1;
}
};