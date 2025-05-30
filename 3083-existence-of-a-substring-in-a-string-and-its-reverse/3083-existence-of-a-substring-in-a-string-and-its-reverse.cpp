class Solution {
public:
    bool isSubstringPresent(string s) {
    int n=s.length();
    for(int i=0;i<n-1;i++){
        char ch=s[i];
        char nch=s[i+1];
        string sb;
        sb+=ch;
        sb+=nch;
        string rsb;
        rsb+=nch;
        rsb+=ch;
        if((s.find(sb)!=string::npos)&&(s.find(rsb)!=string::npos)){
            return true;
        }
    }return false;
}
};