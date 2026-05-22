class Solution {
public:
    void func(int ind, string &curr, string &digits, map<int,string>& mp, vector<string> &ans){
    // abse case
    if(ind == digits.length()){
        ans.push_back(curr);
        return;
    }
    if(ind>digits.length()){
        return;
    }
    for(auto it: mp[digits[ind] - '0']){
        curr.push_back(it);
        func(ind+1, curr, digits, mp, ans);
        curr.pop_back(); // backtracking
    }
}

vector<string> letterCombinations(string digits)
{
    map<int,string> mp={
        {2 , "abc"},
        {3 , "def"},
        {4 , "ghi"},
        {5 , "jkl"},
        {6 , "mno"},
        {7 , "pqrs"},
        {8 , "tuv"},
        {9 , "wxyz"}
    };
    string curr = "";
    vector<string>ans;
    func(0, curr, digits, mp, ans);
    return ans;
}
};