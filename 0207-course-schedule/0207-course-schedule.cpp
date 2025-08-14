class Solution {
public:
    bool detectCycle(vector<vector<int>>& adj){
    int n=adj.size();
    //make the indegree array
    vector<int> indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    
    //start the bfs from the node with indegree 0
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //start the bfs and the topological sorting
    vector<int> topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(topo.size()<n){
        return true;
    }
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>adj(numCourses);
    for(auto it: prerequisites){
        adj[it[1]].push_back(it[0]);
    }
    // for(int i=0;i<numCourses;i++){
    //     vprint(adj[i]);
    // }
    //the courses must not be cyclic in order to be completed, means there shouldnt be any cycle in hte entire graph of the directed course
    if(detectCycle(adj)==true)return false;
    return true;
}
};