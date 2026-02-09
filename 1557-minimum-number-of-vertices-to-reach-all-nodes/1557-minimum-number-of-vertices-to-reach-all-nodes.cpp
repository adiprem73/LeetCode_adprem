class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n);

    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
    }

    // adj vector is ready
    vector<bool> visit(n, false);
    for(auto it: adj){
        for(auto itr: it){
            if(visit[itr]== false){
                visit[itr]= true;
            }
        }
    }

    vector<int> ans;
    for(int i=0;i<visit.size();i++){
        if(visit[i]==false){
            ans.push_back(i);
        }
    }
    return ans;
}

};