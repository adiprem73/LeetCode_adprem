class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // djikstra
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n, 1e7));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>>pq;
        vector<vector<int>> vis(m, vector<int>(n,0));
        pq.push({0,{0,0}});
        effort[0][0]=0;
        vis[0][0]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int eff = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n ){
                    // vis[nr][nc]=1;
                    int difference = abs(heights[nr][nc] - heights[r][c]);
                    int currentEffort = max(eff, difference);
                    // relaxation
                    if(currentEffort < effort[nr][nc]){
                        effort[nr][nc]= currentEffort;
                        pq.push({effort[nr][nc], {nr, nc}});
                    }
                }               
            }
        }
        for(auto it: effort){
            for(auto itr: it){
                cout<<itr<<" ";
            }
            cout<<endl;
        }
        return effort[m-1][n-1];
    }
};