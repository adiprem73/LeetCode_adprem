class Solution {
public:
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<pair<int, int>>> &dir, int m, int n, vector<vector<bool>>& vis){
    vis[r][c]= true;
    auto movement = dir[grid[r][c]];
    for(auto it: movement){
        int nr = r+it.first;
        int nc = c+it.second;
        if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==false){
            for(auto back: dir[grid[nr][nc]]){
                if(back.first == -1*it.first && back.second == -1*it.second){
                    dfs(nr, nc, grid, dir, m, n, vis);
                    break;
                }
            }
            
        }
    }
}

bool hasValidPath(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> vis (m, vector<bool>(n, false));
    vector<vector<pair<int,int>>> dir ={
        {},
        {{0,-1},{0,1}},
        {{-1,0},{1,0}},
        {{0,-1},{1,0}},
        {{1,0},{0,1}},
        {{0,-1},{-1,0}},
        {{-1,0},{0,1}}
    };
    dfs(0,0,grid,dir,m,n,vis);
    if(vis[m-1][n-1]==true){
        return true;
    }else return false;
}
};