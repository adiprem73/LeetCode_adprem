class Solution {
public:
    int func(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp)
{

    // base cases
    if(r<0 || c< 0){
        return 1e9+7;
    }
    if(r==0 && c==0){
        return grid[0][0];
    }

    // check for dp case
    if(dp[r][c]!= -1){
        return dp[r][c];
    }

    // move left
    int left = func(r, c-1, grid, dp);
    int right = func(r-1, c, grid, dp);

    return dp[r][c] = grid[r][c] + min(left, right);
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // make dp array
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return func(m-1, n-1, grid, dp);
}
};