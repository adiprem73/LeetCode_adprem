class Solution {
public:
    int numIslands(vector<vector<char>> & grid){
    int n=grid.size();
    int m= grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m,0));

    int cnt=0;
    vector<int> dx={0,1,0,-1};
    vector<int> dy={-1,0,1,0};
    // cout << "hello" << endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && grid[i][j]=='1'){
                // cout<<"hello"<<endl;
                cnt++;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j]=1;
                while(!q.empty()){
                    auto it= q.front();
                    q.pop();
                    int r= it.first;
                    int c= it.second;

                    for(int k=0;k<4;k++){
                        int nr= r+dx[k];
                        int nc= c+dy[k];
                        if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]=='1'){
                            q.push({nr,nc});
                            vis[nr][nc]=1;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}
};