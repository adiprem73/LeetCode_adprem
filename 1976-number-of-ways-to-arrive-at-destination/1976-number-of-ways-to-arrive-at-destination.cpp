class Solution {
public:
    int countPaths(int n, vector<vector<int>> &roads)
{
    const long long MOD = 1e9 + 7;
    vector<vector<pair<int,long long>>> adj(n);
    for(auto it: roads){
        adj[it[0]].push_back({it[1], it[2]}); //{node, time}
        adj[it[1]].push_back({it[0], it[2]});
    }

    vector<long long> dist(n, LLONG_MAX);
    vector<long long> ways(n,0);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int >>> pq;

    dist[0] = 0;
    ways[0] = 1;
    pq.push({0,0});

    while(!pq.empty()){
        auto [d, node] = pq.top();
        pq.pop();

        if(d> dist[node]) continue;

        for(auto &[adjNode, wt] : adj[node]){
            if(d+wt < dist[adjNode]){ // we have found a shorter path hence we must relax it and then reset the number of ways
                dist[adjNode] = d+wt;
                ways[adjNode] = ways[node]; // the number of ways to reach this node will the same as the number of ways to reach the parent node
                pq.push({dist[adjNode], adjNode});
            }

            else if(d+wt == dist[adjNode]){
                ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
            }
        }
    }
    return ways[n-1]%MOD;
}
};