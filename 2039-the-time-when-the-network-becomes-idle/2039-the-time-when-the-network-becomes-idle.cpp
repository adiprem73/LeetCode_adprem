class Solution {
public:
    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience)
{
    unordered_map<int, vector<int>> adj;
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int n = patience.size();
    // the adjacency list is ready now
    vector<int> time(n, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0}); //{time, node}
    time[0] = 0;
    while (!pq.empty())
    {
        auto [timeTaken, node] = pq.top();
        cout<< " Node : "<<node<<endl;
        pq.pop();
        for (auto neigh : adj[node])
        {
            if (time[neigh] > timeTaken + 1)
            {
                time[neigh] = timeTaken + 1; // relaxed
                pq.push({timeTaken + 1, neigh});
            }
        }
    }
    int ans = INT_MIN;
    for(int i=1;i<n;i++){
        int x =0;
        if(2* time[i] <= patience[i]){
            x = 2* time[i];
        }else if((2* time[i]) %patience[i] == 0){
            x = 2* time[i] + (2* time[i] - patience[i]);
        }else{
            x = 4* time[i] - ((2*time[i] )% patience[i]);
        }
        ans = max(ans, x);
    }
    return ans+1;
}
};