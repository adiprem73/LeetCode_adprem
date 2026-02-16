class Solution {
public:
    string freqAlphabets(string s) {
        string ans="";
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i] == '#'){
                char c1= s[i-1];
                char c2= s[i-2];
                string x;
                x+=c2;
                x+=c1;
                int d = stoi(x);
                ans+='a'+(d-1);
                i-=2;
            }else{
                char ch = s[i];
                int x = ch-'0';
                ans+='a'+(x-1);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};