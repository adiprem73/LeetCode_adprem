class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0 ){
                    q.push({i,j});
                }
            }
        }
        int steps=0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        vector<vector<int>> vis(m, vector<int>(n,0));
        while(!q.empty()){
            int size = q.size();
            steps++;
            for(int i=0;i<size;i++){
                auto [r,c]= q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr = r+dr[i];
                    int nc = c+dc[i];
                    if(nr>= 0  && nr<m && nc>=0 && nc<n && mat[nr][nc]!=0 && vis[nr][nc]==0){
                        mat[nr][nc]= steps;
                        vis[nr][nc]= 1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return mat;
    }
};