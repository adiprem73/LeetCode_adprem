class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool> & visited, int& count){
    // first thing is to makr that node as visited
    visited[u]= true;
    count++;

    for(auto neighbour : adj[u]){
        if(visited[neighbour]== false){
            dfs(neighbour, adj, visited, count);
        }
    }
}

// (x-a)2 + (y-b)2 = r2

int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    vector<vector<int>> adj(n);

    // make the adjacency vector based on what bombs will detoaonte what bombs
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                long long g = bombs[i][0] - bombs[j][0];
                long long h = bombs[i][1] - bombs[j][1];
                long long r = bombs[i][2];
                if (g*g + h*h <= r*r)
                {
                    adj[i].push_back(j);
                }
            }
        }
    } 
    
    // then we just need to find the length of the maximum spanning tree
    int ans =0;
    
    for(int i=0;i<n;i++){
        // we msut perform fresh detonations and fresh chain reactions for eahc node and then take the maximum one
        int count = 0;
        vector<bool> visited(n, false);
        dfs(i, adj, visited, count);
        ans = max(ans, count);
    }
    return ans;
}
};