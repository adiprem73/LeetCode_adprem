class Solution {
public:
   void dfs(int i, vector<vector<int>> & adj, vector<bool>& visit, int & nodes, int & degreeSum){
    visit[i]= true;
    nodes++;
    degreeSum+=adj[i].size();
    for(auto neigh: adj[i]){
        if(visit[neigh]== false){
            dfs(neigh, adj, visit, nodes, degreeSum);
        }
    }
}

int countCompleteComponents(int n, vector<vector<int>> &edges)
{
    // make adj matrix
    vector<vector<int>> adj(n);
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int finalCount=0;
    vector<bool> visit(n, false);
    for(int i=0;i<n;i++){
        if(visit[i]== false){
            // new component found
            int node=0, degreeSum=0;
            dfs(i, adj, visit, node, degreeSum);
            int edges= degreeSum/2;
            cout<<"node : "<<node<<endl;
            cout<<"edges : "<<edges<<endl;
            if(edges == node*(node-1)/2){
                finalCount++;
            }
        }
    }
    return finalCount;
}

};