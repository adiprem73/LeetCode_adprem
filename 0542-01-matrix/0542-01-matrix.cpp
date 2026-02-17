class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    // we will iterate from every zero and keep on updating the distance of each cell from it
    queue<pair<int,int>>q;
    int m = mat.size();
    int n = mat[0].size();
    // vector<vector<int>> ans(m, vector<int>(n, 1e9));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                q.push({i,j});
            }else{
                mat[i][j]= 1e9;
            }
        }
    }
    vector<int> dx={-1, 0, 1, 0};
    vector<int> dy={0, 1, 0, -1};
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        auto [x,y] = node;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && mat[nx][ny]> mat[x][y]+1){
                q.push({nx,ny});
                mat[nx][ny] = mat[x][y]+1;
            }
        }
    }
    return mat;
}
};