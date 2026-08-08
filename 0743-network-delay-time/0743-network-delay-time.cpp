class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // building adjacency list
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times){
            int from = it[0];
            int to = it[1];
            int time = it[2];
            adj[from].push_back({to, time});
        }
        // we will apply djikstra
        vector<int> dist(n+1, 1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>pq;
        pq.push({0, k});
        dist[k]=0;

        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int time = it.first;
            int node = it.second;

            for(auto itr: adj[node]){
                int adjNode = itr.first;
                int costTime = itr.second;
                if(time+costTime < dist[adjNode]){
                    dist[adjNode] = time+costTime;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1;i<dist.size();i++){
            if(dist[i] == 1e9)return -1;
            ans= max(ans, dist[i]);
        }
        return ans;
    }
};