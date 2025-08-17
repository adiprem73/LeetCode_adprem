class Solution {
public:
    const long long MOD = 1e9+7;

int countPaths(int n, vector<vector<int>>& roads) {
    //make the adjacency list
    vector<vector<pair<int,int>>> adj(n);
    for(auto it:roads){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    vector<long long> dist(n, 1e9); //distance array
    vector<long long> ways(n, 0); //ways array

    priority_queue<
        pair<long long,int>, //type of elements stored here(distance,node)
        vector<pair<long long,int>>,  //the underllying contatiner used: a vector
        greater<pair<long long,int>>   //the comparator: smallest element comes first
    > q;
    q.push({0,0});
    dist[0]=0;
    ways[0]=1;

    while(!q.empty()){
        auto it= q.top();
        int node= it.second;
        long long distance= it.first;
        q.pop();
        // cout<<"node : "<<node<<" distance : "<<distance<<endl;

        for(auto iter: adj[node]){
            int adjNode= iter.first;
            int edgeWeight= iter.second;
            // cout<<"adjacent Node : "<<adjNode<<endl;
            // cout<<"edgeweight : "<<edgeWeight<<endl;
            if(distance+edgeWeight< dist[adjNode]){
                dist[adjNode]= distance+edgeWeight;
                // cout<<"dist[adjNode]: "<<distance+edgeWeight<<endl;
                q.push({distance+ edgeWeight, adjNode});
                ways[adjNode]=ways[node];
            }

            else if(dist[adjNode]== distance+edgeWeight){
                ways[adjNode]= (ways[adjNode]+ways[node])%MOD;
            }
        }
        // vprint(dist);
        // vprint(ways)
    }
    // vprint(dist);
    // vprint(ways);
    return ways[n-1];
}
};