class Solution {
public:
    void dfs(int node, vector<vector<int>> &  adj, vector<bool> & visited, vector<int> & currPath, int n, vector<vector<int>> &successPaths){
    // cout<<node<<endl;
    visited[node] = true;
    if(node == n){
        successPaths.push_back(currPath);
        visited[node]= false;
        return;
    }
    // vprint(currPath);

    for(int neigh: adj[node]){
        if(visited[neigh] == false){
            currPath.push_back(neigh);
            dfs(neigh, adj, visited, currPath, n, successPaths);
            currPath.pop_back(); // backtracking
        }
    }
    visited[node] = false; // backtracking
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> paths;
    vector<int> currPath;
    int n= graph.size()-1;
    vector<bool> visited(n+1, false);
    currPath.push_back(0);
    dfs(0, graph, visited, currPath, n, paths);
    // for(auto it: paths){
    //     vprint(it);
    // }

    return paths;

}
};