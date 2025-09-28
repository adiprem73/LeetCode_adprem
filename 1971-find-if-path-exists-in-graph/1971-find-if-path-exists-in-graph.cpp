class Solution {
public:
    bool dfs(int u, int destination, vector<vector<int>>& g, vector<int> &vis){
    //base case
    if(u==destination)return true;
    if(vis[u]!=0)return false; //means we have alredy visited this but we didnt found

    vis[u]=1;

    for(int v: g[u]){
        if(!vis[v] && dfs(v, destination, g, vis))return true;
    }
    return false;
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<int>> g(n);
    for (auto it : edges)
    {
        g[it[0]].push_back(it[1]);
        g[it[1]].push_back(it[0]);
    }
    // make the visited array

    vector<int> vis(n, 0);
    return dfs(source, destination, g, vis);
}
};