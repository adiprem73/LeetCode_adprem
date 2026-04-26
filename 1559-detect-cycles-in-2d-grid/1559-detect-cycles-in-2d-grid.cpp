class Solution {
public:
   bool dfs(int r, int c, int pr, int pc, vector<vector<char>>&grid, vector<vector<bool>> &vis){
    int m = grid.size();
    int n = grid[0].size();
    vis[r][c]= true;
    vector<int> dr= {-1,0,1,0};
    vector<int> dc= {0,1,0,-1};
    for(int i=0;i<4;i++){
        int nr = r+dr[i];
        int nc = c+dc[i];
        if(nr!=pr || nc!=pc){ // it was not the row we just visited
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[r][c]==grid[nr][nc]){
                if(vis[nr][nc] == true){
                    // already visited: cycle detected
                    return true;
                }
                if(dfs(nr,nc,r,c,grid,vis)){
                    return true;
                }
                
            }
        }
        
    }return false;
}

bool containsCycle(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]==false){
                cout << i << " " << j << endl;
                // for(int k=0;k<m;k++){
                //     for(int l =0;l<n;l++){
                //         cout<<vis[k][l]<<" ";
                //     }
                //     cout<<endl;
                // }
                bool flag = dfs(i, j, -1, -1, grid, vis);
                if (flag == true)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
};