class Solution {

private:
    void dfs(int x, int y, vector<vector<int>>& grid, long long &sum){
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]!=0){
                sum+=grid[nx][ny];
                grid[nx][ny]=0;
                dfs(nx, ny, grid, sum);
            }
        }
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    long long sum= grid[i][j];
                    grid[i][j]=0;
                    dfs(i, j, grid, sum);
                    if(sum%k == 0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};