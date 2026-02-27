class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pair<int,int>>> adj(n);
    vector<vector<int>> costs(n, vector<int>(k+2, 1e9));
    for(auto it: flights){
        adj[it[0]].push_back({it[1], it[2]}); 
    }
    // we have made the matrix
    priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, src}});  // (cost,(steps, city))
    costs[src][0] = 0;
    while(!pq.empty()){
        auto [cost, temp] = pq.top();
        int city = temp.second;
        int steps = temp.first;
        pq.pop();

        if (steps > k+1)
            continue;
        if (city == dst)
        {
            return cost;
        }

        for(auto it: adj[city]){
            auto extraCost = it.second;
            auto stop = it.first;
            if(cost+extraCost < costs[stop][steps]){
                pq.push({cost+extraCost, {steps+1,stop}});
                costs[stop][steps] = cost+extraCost;
            }
        }
    }
    return -1;
}
};