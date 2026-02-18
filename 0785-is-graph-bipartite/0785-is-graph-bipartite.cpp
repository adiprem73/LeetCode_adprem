class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n ,-1); // -1: shows that the node is not yet colored
    queue<int> q;
    q.push(0);
    color[0]=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto neigh: graph[node]){
            if(color[neigh] == -1){
                color[neigh]= !color[node];
                q.push(neigh);
            }else{
                if(color[neigh] == color[node]){
                    return false;
                }
            }
        }
    }
    return true;
}
};