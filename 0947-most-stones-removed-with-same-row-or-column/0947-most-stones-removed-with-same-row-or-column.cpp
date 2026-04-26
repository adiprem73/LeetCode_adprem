class DisjointSet
{

public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]); // this is how path compression would take place. we store the parent in parent[node]
    }
    // Union by rank
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by Size
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    int numRows=0, numCols=0;
    for(auto it: stones){
        numRows = max(numRows, it[0]);
        numCols = max(numCols, it[1]);
    }

    DisjointSet ds(numRows+numCols+1);
    // all the nodes will not be inovlved with stones as not all stones are garuenteec to be rpesent at each row and olcumsn. so to trakc the empty rows and ocls we need to store the unique nodes
    unordered_map<int,int> stoneNodes;
    for(auto it: stones){
        int nodeRow = it[0];
        int nodeCol = it[1]+numRows+1;
        ds.unionBySize(nodeRow, nodeCol);
        stoneNodes[nodeRow]=1;
        stoneNodes[nodeCol]=1;
    }

    int cnt =0;
    for(auto it: stoneNodes){
        if(ds.findUPar(it.first) == it.first){
            cnt++; // this will countt eh number of connected components
        }
    }
    return n-cnt;
}
};