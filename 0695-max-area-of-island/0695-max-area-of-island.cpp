class Solution {
public:
    void dfs(int x, int y, vector<vector<bool>> &vis, vector<vector<int>>&grid, int &area){
    vis[x][y]= true;
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && vis[nx][ny] == false)
        {
            area+=1;
            dfs(nx, ny, vis, grid, area);
        }
    }
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> vis (m, vector<bool> (n, false));
    int ans = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && vis[i][j]== false){
                int area =1;
                dfs(i, j, vis, grid, area);
                ans= max(ans, area);
            }
        }
    }
    return ans;
}
};