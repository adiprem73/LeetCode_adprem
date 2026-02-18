class Solution {
public:
    void dfs(int u, vector<vector<int>> & adj, vector<bool> &vis, int &nodes){
    for(auto neigh : adj[u]){
        if(vis[neigh] == false){
            vis[neigh] = true;
            nodes++;
            dfs(neigh, adj, vis, nodes);
        }
    }
}

long long countPairs(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n);
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    // the idea here is the we will start fresh dfs from each node and then based on the visited array we will count the unvisited from eahc dfs --> this idea will give TLE

    // the next idea is to find the number of ndoes in each connected components. suppose it comes out to be {s1, s2, s3, ..}. then the final answe will be s1*s2 + s2*s3 + ...
    vector<int> nos;
    vector<bool> vis(n, false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]= true;
            int nodes =1;
            dfs(i, adj, vis, nodes);
            nos.push_back(nodes);
        }
    }
    for(int i=0;i<nos.size();i++){
        cout<<nos[i]<<endl;
    }
    long long ans = 0;
long long remaining = n;

for(int size : nos){
    remaining -= size;
    ans += (long long)size * remaining;
}
    
    return ans;
}
};