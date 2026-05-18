class Solution {
public:
    int swimInWater(vector<vector<int>>& grid){
    int n = grid.size();

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

    vector<vector<int>> vis(n, vector<int>(n,0));

    pq.push({grid[0][0],{0,0}});

    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int cost = it.first;
        int r = it.second.first;
        int c = it.second.second;

        if(vis[r][c]==1)continue;

        vis[r][c]=1;

        // base case
        if(r == n-1 && c== n-1){
            return cost;
        }

        for(int i=0;i<4;i++){
            int nr = r+dx[i];
            int nc = c+dy[i];

            if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc]==0){
                int newCost = max(cost, grid[nr][nc]);

                pq.push({newCost, {nr,nc}});
            }
        }
    }
    return -1;
}
};