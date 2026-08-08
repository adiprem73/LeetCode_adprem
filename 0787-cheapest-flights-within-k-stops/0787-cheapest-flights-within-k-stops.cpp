class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // (stops, node, cost)
        // building the adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: flights){
            int from = it[0];
            int to = it[1];
            int price = it[2];
            adj[from].push_back({to, price});
        }
        int cst =1e9;
        priority_queue<vector<int>, vector<vector<int>>, greater<>>pq;
        pq.push({0, 0, src});
        vector<int> final(n, 1e9);
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int stops = it[0];
            int cost = it[1];
            int node = it[2];
            cout<<stops<<" "<<cost<<" "<<node<<endl;

            // base cases
            // if(stops>k){
            //     return -1;
            // }
            if(node == dst && stops-1<=k)cst= min(cost, cst);

            // relaxation for djikstra
            for(auto adjNode: adj[node]){
                int nextNode = adjNode.first;
                int price = adjNode.second;
                if(price+cost < final[nextNode]){
                    final[nextNode] = price + cost;
                    pq.push({stops+1, final[nextNode], nextNode});
                }
            }
        }
        return cst == 1e9 ? -1:cst;
    }
};