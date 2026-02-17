class Solution {
public:
    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    vis[x][y] = 1;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for(int i=0;i<4;i++){
        int nx = x+ dx[i];
        int ny = y+ dy[i];
        if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny]==0 && grid[nx][ny]==1){
            dfs(nx, ny, vis, grid);
        }
    }
}

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    vector<vector<int>> vis(m, vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int  j=0;j<n;j++){
            if(i==0 || i==m-1 || j==0 || j==n-1){
                if(grid[i][j] == 1){
                    dfs(i, j, vis, grid);
                }
            }
        }
    }

    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && vis[i][j]==0)cnt++;
        }
    }
    return cnt;
}
};