class Solution {
public:
    void makeadjacency (vector<vector<int>>& edges, vector<vector<int>>& adj){
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
}

long long dfs(int u, int parent, vector<vector<int>> & adj, vector<int>& values, int k, int & components){
    long long cur = values[u]%k;

    for(int v: adj[u]){ //visit all the nodes attached to node u
        if(v== parent)continue;

        long long child = dfs(v, u, adj, values, k, components);
        cur= (cur+child)%k;
    }

    if(cur%k == 0){
        components++;
        return 0; //cut here
    }

    return cur;
}

int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
{
    vector<vector<int>> adj(n);
    makeadjacency(edges, adj);
    // for(auto it: adj){
    //     vprint(it);
    // }

    //the total sum of values must be divisible by k
    long long sum= accumulate(values.begin(), values.end(), 0LL);
    if(sum%k!=0)return 0;

    int components=0;
    dfs(0, -1, adj, values, k, components );

    return components;
}
};