class Solution {
public:
    int func(int i, int j, string word1, string word2, vector<vector<int>> &dp){
    //base case

    if(i<0)return j+1;
    if(j<0)return i+1;

    if(dp[i][j]!=-1)return dp[i][j];
    //matched
    if(word1[i] == word2[j])return dp[i][j] = func(i-1, j-1, word1, word2, dp);

    //if not matched then we can perform three operations: insert delete and replace
    return dp[i][j] = min(1+func(i, j-1, word1, word2, dp), min(1+func(i-1, j, word1, word2, dp), 1+func(i-1, j-1, word1, word2, dp)));
}

int minDistance(string word1, string word2) {
    int n=word1.size();
    int m=word2.size();
    vector<vector<int>> dp(n, vector<int> (m,-1)); 
    int ans=func(n-1, m-1, word1, word2, dp);  
    return  ans;
}
};