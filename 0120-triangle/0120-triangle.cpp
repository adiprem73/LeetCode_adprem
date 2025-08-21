class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
    int n=triangle.size();// number of rowas
    vector<vector<int>> dp(n, vector<int>(n,0));

    // now since we went top to bottom in recursion and in memo,w e will do the opposite in tabulation. in tabulation we always want to start with some wehre thatt we alreayd inow tha vlaue know

    // in this case, we already know that the last row will have itself as the dp wehn we start at bottom

    // setting the last row of dp ss the same as the last row of triangle grid
    for(int j=0;j<n;j++){
        dp[n-1][j]= triangle[n-1][j];
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[i][j]= min(dp[i+1][j], dp[i+1][j+1])+ triangle[i][j];
        }
    }

    return dp[0][0];
}
};