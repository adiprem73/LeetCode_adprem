class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1); // -1: shows that the node is not yet colored
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto neigh : graph[node])
                {
                    if (color[neigh] == -1)
                    {
                        color[neigh] = !color[node];
                        q.push(neigh);
                    }
                    else
                    {
                        if (color[neigh] == color[node])
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int bfs(vector<vector<int>> adj, int currNode, int n){
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(currNode);
    visited[currNode]= true;

    int level = 1;
    while(!q.empty()){
        int size = q.size();
        while(size --){
            int curr = q.front();
            q.pop();

            for(int & ngbr : adj[curr]){
                if(visited[ngbr])continue;

                q.push(ngbr);
                visited[ngbr]= true;
            }
        }
        level++; // one extra will be implemented
    }
    return level-1;
}

int getMaxFromEachComp(vector<vector<int>> adj, int curr, vector<bool>& visited, vector<int>&levels){
    int maxGroup = levels[curr];
    visited[curr]= true;

    for(int & ngbr: adj[curr]){
        if(!visited[ngbr]){
            maxGroup = max(maxGroup, getMaxFromEachComp(adj, ngbr, visited, levels));
        }
    }
    return maxGroup;
}

    int magnificentSets(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n+1);
    for(auto it: edges){
        adj[it[1]-1].push_back(it[0]-1);
        adj[it[0]-1].push_back(it[1]-1);
    }
    if(isBipartite(adj) == false){
        return -1;
    }
    
    // now we will do bfs from each node, so that all disconnected graphs are included. we will count the maximum levels of each bfs and then we will take the sum
    
    vector<int> levels(n,0);
    for(int i=0;i<n;i++){
        levels[i] = bfs(adj, i, n);
    }

    int maxGroupEachComp = 0;
    vector<bool> visited(n, false);
    for(int node =0;node<n;node++){
        if(!visited[node]){
            maxGroupEachComp += getMaxFromEachComp(adj, node, visited, levels);
        }
    }
    return maxGroupEachComp;

}
};