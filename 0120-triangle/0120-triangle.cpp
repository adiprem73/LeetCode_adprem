class Solution {
public:
    int func(int i, int j , vector<vector<int>> & triangle, vector<vector<int>>& dp){
    int n=triangle.size();

    if(i== n-1) return triangle[i][j]; //base case fo the elelment so fht eending row

    if(dp[i][j]!=1e9) return dp[i][j];

    int down= func(i+1, j, triangle, dp);
    int diag= func(i+1, j+1, triangle, dp);

    return dp[i][j]= min(down, diag) + triangle[i][j];
}

int minimumTotal(vector<vector<int>>& triangle){
    int n=triangle.size();// number of rowas
    int m=triangle[triangle.size()-1].size();
    vector<vector<int>> dp(n, vector<int>(m,1e9));

    return func(0,0, triangle, dp);
}
};