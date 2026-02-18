class Solution {
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
{
    unordered_map<string, vector<string>> adj;
    int n = recipes.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<ingredients[i].size();j++){
            adj[ingredients[i][j]].push_back(recipes[i]);
        }
    }
    // now the adjacency list is ready. we jsut need to apply kahns algorithm to this and then check what recipes are available in the topo sort algorithm result

    unordered_map<string, int> indegree;
    for(auto it: adj)
    {
        for(auto itr: it.second){
            indegree[itr]++;
        }
    }

    queue<string> q;
    // push the elemtns with zero indegree into the queue
    for(auto it: adj){
        if(indegree[it.first]==0){
            q.push(it.first);
        }
    }
    vector<string> topo;
    while(!q.empty()){
        string w = q.front();
        q.pop();
        topo.push_back(w);
        for(auto it: adj[w]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    unordered_map<string, int> mp;
    for(auto it: topo){
        mp[it]++;
    }
    vector<string> ans;
    for(auto it: recipes){
        if(mp.count(it)>0){
            ans.push_back(it);
        }
    }
    return ans;
}

};