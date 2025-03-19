class Solution {
public:
    void parentheses(vector<string>& str,int n, int open,int close,string s){
    // cout<<s<<endl;
    if(2*n==s.length()){
        
        str.push_back(s);
    }
    else{
        if(open<n){
            
            parentheses(str,n,open+1,close,s+'(');

        }
        if(close<open){
            
            parentheses(str,n,open,close+1,s+')');
        }
    }
}


vector<string> generateParenthesis(int n) {
    vector<string> str={};
    string s="";
    int open=0;
    int close=0;
    parentheses(str,n,open,close,s);
    return str;
}
};