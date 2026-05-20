class Solution {
public:
    void makeAllPossibleComb(string &curr, int open, int close, int n, vector<string> &ans)
{
    if (curr.length() == 2 * n)
    {
        ans.push_back(curr);
        return;
    }
    if (curr.length() > 2 * n)
    {
        return;
    }

    if(open<n){
        curr.push_back('(');
        makeAllPossibleComb(curr, open+1, close, n, ans);
        curr.pop_back();
    }

    if(close<open){
        curr.push_back(')');
        makeAllPossibleComb(curr, open, close+1, n, ans);
        curr.pop_back();
    }
    
    
}


vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string curr = "";

    int open=0, close=0;

    makeAllPossibleComb(curr,0,0, n, ans);
    // vector<string> finalAns;
    // for (auto it : ans)
    // {
    //     if (isValid(it))
    //     {
    //         finalAns.push_back(it);
    //     }
    // }
    return ans;
}
};