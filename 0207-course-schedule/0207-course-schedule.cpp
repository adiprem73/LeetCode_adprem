class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // first build the adj vector
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        vector<int> indegree(numCourses,0);
        // update the indegrees
        for(auto it: adj){
            for(auto itr: it){
                indegree[itr]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto adjNode: adj[node]){
                indegree[adjNode] -- ;
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
        return topo.size() == numCourses;
    }
};