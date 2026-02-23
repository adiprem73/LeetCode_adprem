class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if(grid[0][0] == 1 || grid[n-1][n-1] == 1)return -1;
    // make a visited matrix
    vector<vector<int>> vis(n, vector<int>(n, 0));
    // make a queue that can store (row, col, steps)
    queue<pair<pair<int, int>, int>> q; // (row, col, steps)
    // we always start with the starting node (0,0)
    q.push({{0,0},1});
    vis[0][0] = 1;

    while(!q.empty()){
        auto [coordinates, dist]= q.front();
        q.pop();
        int r = coordinates.first;
        int c = coordinates.second;
        if(r==n-1 && c == n-1)return dist;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nr =r+i;
                int nc =c+j;
                if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc] == 0 && grid[nr][nc] != 1){
                    vis[nr][nc]= 1;
                    q.push({{nr, nc}, dist + 1});
                }
            }
        }
    }
    return -1;
}
};