class Solution {
public:
    void dfs(int u, vector<vector<int>> &adj, vector<bool> & visited){
    // mark this visited
    visited[u]= true;
    for(auto neighbours: adj[u]){ // traverse through all the neighbouring nodes
        if(visited[neighbours] == false){
            dfs(neighbours, adj, visited);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    // the very first thing to do will be to convert the graph from matrix form to vector form so that we can perform  our traversals easily
    int n = isConnected.size();
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // we will maintain a count variable to count the number of times dfs gets called from this main function: this will only give the correct number of provinces
    int cnt=0;


    // now first we will try for a dfs approach
    // for this we will need a visited array as well so that we do not go aorund in circles
    vector<bool> visited(n);
    for(int i=0;i<n;i++){
        if(visited[i]== false){
            dfs(i, adj, visited);
            cnt++;
        }
    }
    return cnt;
}
};