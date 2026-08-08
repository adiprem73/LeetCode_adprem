class Solution {
public:

    static const int MOD = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // building the adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: roads){
            int u = it[0];
            int v = it[1];
            int time = it[2];
            adj[u].push_back({v, time}); //(node, time);
            adj[v].push_back({u, time});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<long long > ways(n,0);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>>pq;
        pq.push({0, 0}); //{time, node}
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            long long time = temp.first;
            long long node = temp.second;

            if(time > dist[node])continue;

            for(auto neigh : adj[node]){
                long long nextNode = neigh.first;
                long long costTime = neigh.second;
                if(dist[nextNode] > time + costTime){
                    ways[nextNode] = ways[node];
                    dist[nextNode] = time+ costTime;
                    pq.push({dist[nextNode], nextNode});
                }else if(dist[nextNode] == time + costTime){
                    ways[nextNode]=( ways[node] + ways[nextNode])%MOD;
                }
            }
        }
        return ways[n-1]%MOD;
    }
};