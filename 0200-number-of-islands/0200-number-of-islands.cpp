class Solution {
public:
    vector<int> dx = {0,1,0,-1};
vector<int> dy = {-1,0,1,0};

void dfs(int r, int c, vector<vector<char>> &grid, vector<vector<int>> &visit)
{
    visit[r][c] = 1;
    int n = grid.size();
    int m = grid[0].size();
    
    for (int i = 0; i < 4; i++)
    {
        int nrow = r + dx[i];
        int ncol = c + dy[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visit[nrow][ncol] == 0 && grid[nrow][ncol] == '1')
        {
            dfs(nrow, ncol, grid, visit);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visit(n, vector<int>(m, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j] && grid[i][j] == '1')
            {
                dfs(i, j, grid, visit);
                cnt++;
            }
        }
    }
    return cnt;
}
};