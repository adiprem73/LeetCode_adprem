class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // i will just use bfs
        queue<pair<int,int>> q; //(row, col)
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int dr[]= {-1,0,1,0};
        int dc[]= {0,1,0,-1};
        int steps=0;
        

        while(!q.empty()){
            int size = q.size();
            steps++;
            for(int i=0;i<size;i++){
                auto [r,c] = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int nr = r+dr[j];
                    int nc = c+dc[j];
                    // checking
                    if(nr>=0 && nr<m && nc>=0 && nc<n){
                        if(mat[nr][nc] != 0 && vis[nr][nc] == 0){
                            vis[nr][nc]=1;
                            mat[nr][nc]= steps;
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
        return mat;
    }
};