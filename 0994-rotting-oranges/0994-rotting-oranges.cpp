class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();

    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> vis(n, vector<int>(m,0));
    // cout<<"hello";
    //declaring starting nodes
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                //mark them rotten in the visited array as well
                vis[i][j]=2;
            }
            else{
                vis[i][j]=0;
            }
        }
    }

    int tm=0;
    vector<int> drow={-1, 0, 1, 0};
    vector<int> dcol={0, 1, 0, -1};
    while(!q.empty()){
        auto node=q.front();
        int r=node.first.first;
        int c=node.first.second;
        int t=node.second;
        tm=max(tm,t);
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                q.push({{nrow,ncol},t+1});
                vis[nrow][ncol]=2;
            }
        }
        // for(int i=0;i<vis.size();i++){
        //     vprint(vis[i]);
        // }

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]!=2 && grid[i][j]==1){
                return -1;
            }
        }
    }
    return tm;
}
};