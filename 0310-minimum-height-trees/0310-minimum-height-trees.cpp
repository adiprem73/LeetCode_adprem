class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges){
    if(n==1)return {0};
    // first we need to make the adjacency list
    vector<vector<int>> adj(n);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    // the idea here is that we will find all the leaf nodes. that is those with their indegree as 1. then we will remove them one by one layer by layer evenly from all sides which will give us the answer at last

    // first find the indregree of each elelment
    vector<int> indegrees(n);
    for(auto it: edges){
        for(auto itr: it){
            indegrees[itr]++;
        }
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegrees[i]==1){
            q.push(i);
        }
    }
    int remaining= n;

    while (remaining > 2)
    {
        int size = q.size();
        remaining -= size;

        while (size--)
        {
            int node = q.front();
            q.pop();

            for (auto nei : adj[node])
            {
                indegrees[nei]--;
                if (indegrees[nei] == 1)
                    q.push(nei);
            }
        }
    }

    vector<int> ans;
    while(q.empty()== false){
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}
};