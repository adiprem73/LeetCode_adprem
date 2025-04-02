class Solution {
public:
    bool vowelcheck(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
            return true;
        }
        return false;
    }

    bool alphacheck(char c){
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
            return true;
        }
        return false;
    }

    bool worthy(string s){
        bool flag=false;
        for(int i=0;i<s.length();i++){
            if(vowelcheck(s[i])){
                flag=true;
                break;
            }
        }
        return flag;
    }

    string reverseVowels(string s) {
        if(worthy(s)){
            int start=0;
            int end=s.length()-1;
            while(start<end){
                int vfirst=0;
                int vlast=0;
                for(int i=start;i<s.length();i++){
                    if(alphacheck(s[i])&&vowelcheck(s[i])){
                        vfirst=i;
                        start=i+1;
                        break;
                    }
                }
                for(int i=end;i>=0;i--){
                    if(alphacheck(s[i])&&vowelcheck(s[i])){
                        vlast=i;
                        end=i-1;
                        break;
                    }
                }
                if(vfirst<vlast){
                    char temp=s[vfirst];
                    s[vfirst]=s[vlast];
                    s[vlast]=temp;
                }
            }
            return s;
        }
        else{
            return s;
        }
        return "";
    }
};