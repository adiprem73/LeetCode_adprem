class Solution {
public:
    void func(string curr, int ind, string pattern, vector<int>& used, int &n, vector<string> &ans){
    // base case
    if(curr.length()==n+1){
        ans.push_back(curr);
        return;
    }
    // cout<<curr<<endl;

    if(pattern[ind]=='I'){
        char lastChar = curr[curr.length()-1];
        int lastDigit = lastChar-'0';
        for(int i=lastDigit+1 ; i<=9 ; i++){
            if(used[i]==-1){
                used[i]=1;
                func(curr + to_string(i), ind + 1, pattern, used, n, ans);
                used[i] = -1;
            }
            
        }
    }

    if (pattern[ind] == 'D')
    {
        char lastChar = curr[curr.length() - 1];
        int lastDigit = lastChar - '0';
        for (int i = lastDigit - 1; i>=1; i--)
        {
            if (used[i] == -1)
            {
                used[i] = 1;
                func(curr + to_string(i), ind + 1, pattern, used, n, ans);
                used[i] = -1;
            }
        }
    }
}

string smallestNumber(string pattern)
{
    vector<string> ans;

    int n = pattern.size();
    for (int i = 1; i <= 9; i++)
    {
        vector<int> used(10, -1);
        used[i] = 1;
        func(to_string(i), 0, pattern, used, n, ans);
    }

    // for(auto it: ans){
    //     cout<<it<<endl;
    // }

    sort(ans.begin(), ans.end());
    return ans[0];
}
};