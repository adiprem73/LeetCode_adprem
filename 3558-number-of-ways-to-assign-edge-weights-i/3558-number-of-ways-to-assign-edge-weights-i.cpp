class Solution {
public:
    long long modPow(long long a, long long b)
{
    long long mod = 1e9 + 7;
    long long res = 1;

    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

int assignEdgeWeights(vector<vector<int>> &edges)
{
    unordered_map<int, vector<int>>adj;
    int n=INT_MIN;
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
        n= max(n, max(it[0],it[1]));
    }
    vector<int> vis(n+1,0);
    // we need to start bfs by 1 always
    queue<int> q;
    q.push(1);
    vis[1]=1;
    int d=0;
    while(!q.empty()){
        d++;
        int size = q.size();
        for(int i=0;i<size;i++){
            int node = q.front();
            q.pop();
            for(auto neighbour : adj[node]){
                if(vis[neighbour]==0){
                    q.push(neighbour);
                    vis[neighbour]=1;
                }                
            }
        }
    }
    // cout<<d-1;
    int depth = d-1;
    long long ans = modPow(2, depth-1);
    return ans;
}
};