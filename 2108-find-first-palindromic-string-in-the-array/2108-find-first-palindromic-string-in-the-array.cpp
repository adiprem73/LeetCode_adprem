class Solution {
public:
    bool palindromeCheck(string s){
    string t = s;
    reverse(s.begin(),s.end());
    return t==s;
}

string firstPalindrome(vector<string>& words) {
    for(auto it: words){
        if(palindromeCheck(it)== true){
            return it;
        }
    }return "";
}
};