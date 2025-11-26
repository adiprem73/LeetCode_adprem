class Solution {
public:
const int MOD = 1000000007;

int dfs(int r, int c, vector<vector<int>> &grid, int k, int rem, vector<vector<vector<int>>> &dp)
{
    int n = grid.size();
    int m = grid[0].size();

    rem = (rem + grid[r][c]) % k;

    if (dp[r][c][rem] != -1)
    {
        return dp[r][c][rem];
    }

    if(r==n-1 && c==m-1){
        return (rem==0);
    }

    long long ways=0;

    // move right
    if (c + 1 < m)
    {
        ways+= dfs(r, c + 1, grid, k, rem, dp);
    }

    // move down
    if (r + 1 < n)
    {
        ways+= dfs(r + 1, c, grid, k, rem,  dp);
    }

    return dp[r][c][rem] = ways%MOD;
}

int numberOfPaths(vector<vector<int>> &grid, int k)
{
    int n = grid.size();
    if (!n)
    {
        return 0;
    }
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k,-1)));

    return dfs(0,0, grid, k, 0 , dp);
}


};