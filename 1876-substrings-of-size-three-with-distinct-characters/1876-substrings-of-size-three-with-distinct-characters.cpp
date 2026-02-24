class Solution {
public:
    bool checkString(string s){
    if(s[0] == s[1] || s[1] == s[2] || s[2] == s[0])return false;

    return true;
}

int countGoodSubstrings(string s)
{
    int n = s.length();
    if(n<3)return 0;
    string window = s.substr(0, 3);
    int cnt =0;
    if(checkString(window) == true) cnt++;
    for(int i=1;i<n-3+1;i++){
        window[0] = window[1];
        window[1] = window[2];
        window[2] = s[i+2];
        if(checkString(window)) cnt++;
    }
    return cnt;
}
};