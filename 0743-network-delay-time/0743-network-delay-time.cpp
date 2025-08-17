class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pair<int, int>>> adj(n+1);
    vector<int> vis(n+1, 1e9);
    
    for (auto it : times)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    queue<pair<int, int>> q; // time,node
    q.push({0, k});
    vis[k]=0;


    while (!q.empty())
    {
        auto temp = q.front();
        int node = temp.second;
        int time = temp.first;
        q.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;
            if (time + edgeWeight < vis[adjNode])
            {
                vis[adjNode] = time + edgeWeight;
                q.push({time + edgeWeight, adjNode});
            }
        }
    }

    int minTime= 0;
    for(int i=1;i<=n;i++){
        minTime=max(minTime, vis[i]);
    }


    if(minTime==1e9)return -1;
    return minTime;
}
};