class Solution {
public:
    bool dfs(int x, int y, vector<vector<bool>> &vis, vector<vector<int>> &grid1, vector<vector<int>> & grid2)
{
    vis[x][y] = true;
    int m = grid1.size();
    int n = grid1[0].size();
    bool isSub = (grid1[x][y] == 1); 
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid2[nx][ny] == 1 && vis[nx][ny] == false)
        {
            if(dfs(nx, ny, vis, grid1, grid2)==false){
                isSub = false;
            }
            
        }
    }
    return isSub;
}

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    int m = grid1.size();
    int n = grid1[0].size();

    vector<vector<bool>> vis(m, vector<bool>(n, false));

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == false && grid2[i][j] == 1 )
            {
                if(dfs(i, j, vis, grid1, grid2)){
                    cnt++;
                }                
            }
        }
    }
    return cnt;
}
};