class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // to solve this problem, we just need to reverse the edges and then do topo Sort
        int n= graph.size();
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++){
            for(auto it: graph[i]){
                adj[it].push_back(i);
            }
        }

        // now that the edges have been reversed, we need to do topo sort
        vector<int> indegrees(n,0);
        for(auto it: adj){
            for(auto itr: it){
                indegrees[itr]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegrees[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto adjNode : adj[node]){
                indegrees[adjNode]--;
                if(indegrees[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }

        sort(topo.begin(), topo.end());
return topo;


    }
};