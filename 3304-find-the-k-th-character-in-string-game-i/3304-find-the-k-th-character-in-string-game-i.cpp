class Solution {
public:
    char func(string s, int k){
    if(s.length()>=k){
        return s[k-1];
    }
    // cout<<s<<endl;
    string temp="";
    for(auto it: s){
        char c = it+1;
        temp+=c;
    }

    s= s+temp;
    return func(s, k);
}

char kthCharacter(int k)
{
    return func("a", k);
}
};