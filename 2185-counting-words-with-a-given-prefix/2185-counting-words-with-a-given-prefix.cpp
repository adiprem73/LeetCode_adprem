class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.length();
        int cnt=0;
        for(auto it: words){
            string substring = it.substr(0, n);
            if(substring == pref)cnt++;
        }
        return cnt;
    }
};