class Solution {
public:
    
void func(int ind, string &s, string &curr, vector<string>& ans){
    // base case
    if(ind == s.length()){
        ans.push_back(curr);
        return;
    }
    if(isalpha(s[ind])){
        curr.push_back(tolower(s[ind]));
        func(ind+1, s, curr, ans);
        curr.pop_back();
        curr.push_back(toupper(s[ind]));
        func(ind+1, s, curr, ans);
        curr.pop_back();
    }

    else{
        curr.push_back(s[ind]);
        func(ind+1, s, curr, ans);
        curr.pop_back();
    }
}

vector<string> letterCasePermutation(string s) {
    string curr = "";
    vector<string> ans ;
    func(0, s, curr, ans);
    return ans;
}
};