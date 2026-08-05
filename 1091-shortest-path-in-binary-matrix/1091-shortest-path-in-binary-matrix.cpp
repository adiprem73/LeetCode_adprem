class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // build adjacency vector from adj amtrix
        if(grid[0][0] == 1)return -1;
        int n = grid.size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(n,-1));
        q.push({{0,0},1});
        vis[0][0]=1;
        while(!q.empty()){
            auto [cell, steps]=q.front();
            q.pop();
            int r = cell.first;
            int c = cell.second;
            if(r==n-1 && c==n-1)return steps;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr = r+i;
                    int nc = c+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 0 && vis[nr][nc] == -1){
                        vis[nr][nc]=1;
                        q.push({{nr,nc}, steps+1});
                    }
                }
            }
        }        
        return -1;
    }
};