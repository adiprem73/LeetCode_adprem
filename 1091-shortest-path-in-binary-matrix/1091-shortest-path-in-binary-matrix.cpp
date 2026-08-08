class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1)return -1;
        if (grid[n - 1][n - 1] == 1)
            return -1;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<vector<int>> q;
        q.push({0, 0}); //(row, col, steps)
        vis[0][0] = 1;
        
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            steps++;
            for (int k = 0; k < size; k++) {
                auto it = q.front();
                q.pop();
                int r = it[0];
                int c = it[1];
                // cout<<"Hello"<<endl;
                if (r == n - 1 && c == n - 1)
                    return steps;
                // cout<<"Hello5"<<endl;
                for (int i = -1; i <= 1; i++) {
                    // cout<<"Hello6"<<endl;
                    for (int j = -1; j <= 1; j++) {
                        if(i==0 && j==0)continue;
                        int nr = r + i;
                        int nc = c + j;

                        if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                            grid[nr][nc] == 0 && vis[nr][nc]==0) {
                            cout << nr << " " << nc << endl;
                            q.push({nr, nc});
                            vis[nr][nc]=1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};