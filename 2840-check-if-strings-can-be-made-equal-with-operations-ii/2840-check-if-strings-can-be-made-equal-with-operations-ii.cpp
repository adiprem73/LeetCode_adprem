class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string st1,st2,st3,st4;
        int n = s1.length();
        for(int i=0;i<n;i++){
            if(i%2==0){
                st1+=s1[i];
            }
            else{
                st2+=s1[i];
            }
        }
        for(int i=0;i<n;i++){
            if(i%2==0){
                st3+=s2[i];
            }
            else{
                st4+=s2[i];
            }
        }
        sort(st1.begin(), st1.end());
        sort(st2.begin(), st2.end());
        sort(st3.begin(), st3.end());
        sort(st4.begin(), st4.end());
        return st1==st3 && st2==st4;
    }
};