class Solution {
public:

class DisjointSet {
    vector<int> parent, size;

    public :
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }  

    int findUParent(int u){
        if(parent[u] == u)return u;

        return parent[u] = findUParent(parent[u]);
    }

    void unionBySize(int u, int v){
        int ulpv = findUParent(v);
        int ulpu = findUParent(u);

        if(ulpv == ulpu) return;

        if(size[ulpv] > size[ulpu]){
            parent[ulpu] = ulpv;
            size[ulpv] += size[ulpu];
        }
        else{
            parent[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
        }
    }
};

    int removeStones(vector<vector<int>>& stones) {
        int maxRows=0, maxCols=0;
        for(auto it: stones){
            maxRows = max(maxRows, it[0]);
            maxCols = max(maxCols, it[1]);
        }

        // now that we have found the number of rows and cols. we will tru to build the dsu
        DisjointSet ds(maxRows + maxCols +2);
        unordered_map<int,int> mp;
        for(auto it: stones){
            int u = it[0];
            int v = it[1] + maxRows +1;
            mp[u] =1;
            mp[v] =1;
            if(ds.findUParent(u) != ds.findUParent(v)){
                ds.unionBySize(u,v);
            }
        }
        // now we just need to find the number of connected components nc
        int nc =0;
        int n = stones.size();
        for(auto it: mp){
            int node = it.first;
            if(ds.findUParent(node) == node){
                nc++;
            }
        }
        return n-nc;
    }
};