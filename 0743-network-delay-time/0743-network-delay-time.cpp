class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }
        // now we will apply standard djikstra
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>pq;
        pq.push({0,k}); // (cost, node)

        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();
            for(auto iter: adj[node]){
                int adjNode = iter.first;
                int edW = iter.second;
                if(edW + cost < dist[adjNode]){
                    dist[adjNode] = edW+cost;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = 0;
        for(int i=1;i<n+1;i++){
            // cout<<dist[i]<<" ";
            if(dist[i] == 1e9)return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};