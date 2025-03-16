class Solution {
public:
    string removeOuterParentheses(string s) {
    int counter=0;
    string substring;
    vector<string> res;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        substring+=ch;
        if(ch=='('){
            counter++;
        }
        else if(ch==')'){
            counter--;
        }
        if(counter==0){
            res.push_back(substring);
            substring="";
        }
    }
    string finres;
    for(int i=0;i<res.size();i++){
        string temp=res[i].substr(1,res[i].length()-2);
        finres+=temp;
    }
    return finres;    
}
};