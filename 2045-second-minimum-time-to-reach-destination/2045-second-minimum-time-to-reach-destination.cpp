class Solution {
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
{
    vector<vector<int>> adj(n+1);
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> dist1(n+1, 1e9);
    vector<int> dist2(n + 1, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto [curTime, node] = pq.top();
        pq.pop();
        int sig= curTime/change;
        if(sig %2 != 0){
            while(curTime%change != 0){
                curTime++;
            }
        }
        for(auto neigh : adj[node]){
            if(curTime + time < dist1[neigh]){
                dist1[neigh] = curTime+ time;
                pq.push({dist1[neigh] , neigh});
            }else if(curTime + time < dist2[neigh]){
                dist2[neigh] = curTime + time;
                pq.push({dist2[neigh], neigh});
            }
        }
    }
    return dist2[n];
}
};