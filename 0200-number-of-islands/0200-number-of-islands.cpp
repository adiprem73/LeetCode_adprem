class Solution {
public:

// this questions just comes down to counting of the number of provinces

    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>&grid){
        vis[r][c]= 1;
        int m = grid.size();
        int n = grid[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr< m && nc>=0 && nc<n && vis[nr][nc]==0 && grid[nr][nc]=='1'){
                dfs(nr, nc, vis, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j] ==0 && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};