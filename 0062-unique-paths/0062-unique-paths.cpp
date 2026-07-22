class Solution {
public:
    int func(int m, int n, vector<vector<int>> & dp)
{
    // this time we need to make it bottms up
    // base case
    if(m<0 || n<0){
        return 0;
    }

    if(m==0 && n==0){
        return 1;
    }

    // dp check
    if(dp[m][n] !=-1){
        return dp[m][n];
    }
    int top = func(m-1, n, dp);
    int left = func(m, n-1, dp);

    return dp[m][n] = top + left;
}

int uniquePaths(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n,-1));
    return func(m-1, n-1, dp);
}
};