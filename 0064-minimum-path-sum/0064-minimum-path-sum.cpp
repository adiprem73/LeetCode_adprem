class Solution {
public:
    int func(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &dp){
        int m = grid.size();
        int n = grid[0].size();
        // base case
        if(r==m || c==n){
            return 1e7;
        }
        if(r==m-1 && c==n-1)return grid[r][c];

        if(dp[r][c]!=-1)return dp[r][c];

        int right=0, down =0;
        // moving right
        right = grid[r][c]+ func(r, c+1, grid, dp);

        // moving down
        down = grid[r][c]+ func(r+1, c, grid, dp);

        return dp[r][c] = min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(0,0,grid, dp);
    }
};