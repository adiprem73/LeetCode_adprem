class Solution {
public:

    bool dfs(int node, int color, vector<int> & colors, vector<vector<int>>&graph){
        for(int adjNode: graph[node]){
            if(colors[adjNode]==-1){
                colors[adjNode] = 1-color;
                if(dfs(adjNode, 1-color, colors, graph)==false){
                    return false;
                }
            }else{
                if(colors[adjNode] == color)return false;
            }
        }
        return true;
    }

// if graph has odd length cycle: it cannot be bipartite
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                if(dfs(i, 0, colors, graph) == false)return false;
            }
        }
        return true;
    }
};