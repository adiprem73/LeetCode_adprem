class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int n=isWater.size();
    int m=isWater[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<vector<int>> dist(n,vector<int>(m,0));

    queue<pair<pair<int,int>,int>> q;
    //declaring starting nodes
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(isWater[i][j]==1){
                q.push({{i,j},0});
                vis[i][j]=1;
            }
            else{
                vis[i][j]=0;
            }
        }
    }


    vector<int> drow={-1,0,1,0};
    vector<int> dcol={0,1,0,-1};
    while(!q.empty()){
        auto node=q.front();
        int r=node.first.first;
        int c=node.first.second;
        int step= node.second;
        q.pop();
        dist[r][c]=step;
        for(int i=0;i<4;i++){
            int nrow=r+drow[i];
            int ncol=c+dcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol}, step+1});
            }
        }
    }
    return dist;
}
};