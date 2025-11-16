class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int i=0,j=0;
        while(i<s.length(), j<s.length()){
            if(s[i]==s[j]){
                i++;
                j++;
            }else{
                return t[i];
            }
        }
    }
};