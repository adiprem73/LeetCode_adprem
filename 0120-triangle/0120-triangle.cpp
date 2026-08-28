class Solution {
public:
    int func(int row, int col, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        int n = triangle.size();
        if(row == n-1){
            return triangle[row][col];
        }

        if(dp[row][col] != INT_MAX)return dp[row][col];

        int down = func(row+1, col, triangle, dp);

        int diag = func(row+1, col+1, triangle, dp);

        return dp[row][col] = triangle[row][col] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return func(0, 0, triangle, dp);
    }
};