class Solution {
public:

    bool dfs(int node, vector<int> &pathVis, vector<int> &vis, int n,  vector<vector<int>>& adj){
        vis[node]=1;
        pathVis[node]=1;
        for(auto adjNode : adj[node]){
            if(vis[adjNode] == 0){ // it is already visited
                if(dfs(adjNode, pathVis, vis, n, adj) == false){
                    return false;
                }
            }else if(pathVis[adjNode] == 1){
                return false;
            }         
        }
        pathVis[node]=0;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        // for this we need to detect cycles in an directed grpahs
        // there are two ways to do this: 
        // 1. using dfs(vis and pathVis)
        // 2. using Kahn's Algorithm

        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(vis[i] == 0){
                if(dfs(i, pathVis, vis, numCourses, adj) == false){
                    return false;
                }
            }
        }
        return true;

    }
};