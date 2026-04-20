class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    queue<pair<int,int>> q;

    // initialize
    for(auto &it: sources){
        int r = it[0], c = it[1], color = it[2];
        grid[r][c] = color;
        dist[r][c] = 0;
        q.push({r, c});
    }

    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};

    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nr = r + dx[i];
            int nc = c + dy[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m){

                // first time visit
                if(dist[nr][nc] == INT_MAX){
                    dist[nr][nc] = dist[r][c] + 1;
                    grid[nr][nc] = grid[r][c];
                    q.push({nr, nc});
                }
                // same-time arrival
                else if(dist[nr][nc] == dist[r][c] + 1){
                    grid[nr][nc] = max(grid[nr][nc], grid[r][c]);
                }
            }
        }
    }

    return grid;
}
};