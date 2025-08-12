class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>&grid, vector<vector<int>> &vis){
    vis[r][c]=1;
    int n=grid.size();
    int m=grid[0].size();
    vector<int> drow={-1,0,1,0};
    vector<int> dcol={0,1,0,-1};
    for(int i=0;i<4;i++){
        int nrow=r+drow[i];
        int ncol=c+dcol[i];
        //check if valid and perform further dfs
        if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&vis[nrow][ncol]!=1&&grid[nrow][ncol]==1){
            dfs(nrow,ncol,grid,vis);
        }
    }
}

int numEnclaves(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    //only start dfs for the boundary elements
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0 || i==n-1 || j==m-1){
                if(grid[i][j]==1 && vis[i][j]!=1){
                    dfs(i,j,grid,vis);
                }
            }
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]==0){
                cnt++;
            }
        }
    }
    return cnt;
}
};