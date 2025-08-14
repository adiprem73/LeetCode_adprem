class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> indegree(n);
    vector<vector<int>> rgraph(n);

    //reversal and indegreeof the reversed grpah is calculated
    for(int i=0;i<n;i++){
        // i->it
        // it->i
        for(auto it: graph[i]){
            rgraph[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    vector<int> safenode;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        safenode.push_back(node);
        for(auto it: rgraph[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    sort(safenode.begin(),safenode.end());
    return safenode;
}
};