class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &src, vector<int>& trg, vector<int>& source, vector<int>& target){
    vis[node]=1;
    src.push_back(source[node]);
    trg.push_back(target[node]);
    for(auto adjNode: adj[node]){
        if(vis[adjNode] == 0){
            dfs(adjNode, adj, vis, src, trg, source, target);
        }
    } 
}

int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
{
    // the very first job is to make source into a graph
    int n = source.size();
    vector<vector<int>> adj(n);
    for(auto it: allowedSwaps){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    // for(auto it: adj){vprint(it);}
    // now we will perform dfs
    int totalAns =0;
    vector<int> vis(n,0);
    vector<int> src, trg;
    for(int i=0;i<n;i++){
        src.clear();
        trg.clear();
        if(vis[i] == 0){
            dfs(i, adj, vis, src, trg, source, target);
        }
        // vprint(src);
        // vprint(trg);
        unordered_map<int, int> freq;

        for (int x : trg)
        {
            freq[x]++;
        }

        int cnt = 0;
        for (int x : src)
        {
            if (freq[x] > 0)
            {
                freq[x]--;
            }
            else
            {
                cnt++;
            }
        }

        totalAns+=cnt;
    }
    return totalAns;
}
};