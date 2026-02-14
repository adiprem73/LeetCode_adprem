class Solution {
public:
    string truncateSentence(string s, int k) {
        string word = "";
        string ans = "";
        s+=" ";
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch==' '){
                k--;
                ans+=word;
                word= "";
                if(k==0){
                    break;
                }
            }else{
                word+=ch;
            }
        }
        return ans;
    }
};