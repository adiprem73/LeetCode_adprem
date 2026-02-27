class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int,int>>> adj(n+1);
    for(auto it: times){
        adj[it[0]].push_back({it[1], it[2]}); // {node, time}
    }
    // the adjacency list is ready now
    vector<int> time(n+1, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, k}); //{time, node}
    time[k]= 0;
    while(!pq.empty()){
        auto [timeTaken, node] = pq.top();
        pq.pop();
        for(auto neigh : adj[node]){
            int wt = neigh.second;
            int nd = neigh.first;
            if(time[nd] > timeTaken+wt){
                time[nd] =  timeTaken+wt; // relaxed
                pq.push({timeTaken+wt, nd});
            }
        }
    }
    int sum =0;
    for(int i=1;i<n+1;i++){
        if(time[i] == 1e9)return -1;
        else{
            sum = max(sum, time[i]);
        }
    }
    return sum;
}
};