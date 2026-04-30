class Solution {
public:
    int dfs(int r, int c, int cost, vector<vector<int>>& grid, int k, vector<vector<vector<int>>> &dp){
    int m = grid.size();
    int n = grid[0].size();

    // if r and c even one of them exceed the limit, then it becomes impossible to reach the end
    if(r>=m || c>=n) return -1e9;

    if (grid[r][c] != 0)
        cost++;
    // if the current cost exceeds the limit k, then also it becomes impossible to reach the end
    if(cost > k)return -1e9;

    if(r==m-1 && c==n-1){
        return grid[r][c]; // if we have alredy reached the destianti then then return that value only. we know that dp in memoisation is a bottom-up approach. it will start filling from the down
    }

    if(dp[r][c][cost] != -1){
        return dp[r][c][cost];
    }

    int right = dfs(r, c+1, cost, grid, k , dp);
    int down = dfs(r+1, c, cost, grid, k, dp);

    return dp[r][c][cost] = grid[r][c] + max(right, down);
}

int maxPathScore(vector<vector<int>> &grid, int k)
{
    int m = grid.size(), n = grid[0].size();

    vector dp(m, vector(n, vector<int>(k + 1, -1)));

    int ans = dfs(0, 0, 0, grid, k, dp);

    return ans < 0 ? -1 : ans;
}

};