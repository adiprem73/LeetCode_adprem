class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(); // number of rows
        int n = heights[0].size(); // number of columns
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq; // {dist, {row, col}}
        pq.push({0, {0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        vector<vector<int>> dist(m, vector<int>(n,1e7));
        dist[0][0]=0;
        while(!pq.empty()){
            auto [difference, cell]= pq.top();
            int r = cell.first;
            int c = cell.second;
            pq.pop();
            if(r==m-1 && c==n-1){
                return difference;
            }
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(!(nr>=0 && nr<m && nc>=0 && nc<n)){
                    continue;
                }
                int diff = abs(heights[r][c] -heights[nr][nc]);
                int newEffort = max(diff, difference);
                // djikstra relaxation
                if(newEffort < dist[nr][nc]){
                    dist[nr][nc]= newEffort;
                    pq.push({dist[nr][nc],{nr,nc}});
                }
                
            }
        }
        // for(auto it: dist){
        //     for(auto itr: it){
        //         cout<<itr<<" ";
        //     }
        //     cout<<endl;
        // }
        return 0;
    }
};