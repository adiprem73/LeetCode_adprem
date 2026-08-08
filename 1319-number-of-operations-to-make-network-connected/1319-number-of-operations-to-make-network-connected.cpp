class Solution {
public:
class DisjointSet{
    vector<int> size, parent;

    public:
    DisjointSet(int n){
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findUParent(int u){
        if(parent[u] == u)return u;

        return parent[u] = findUParent(parent[u]);
    }

    void unionBySize(int u, int v){
        int ulpu = findUParent(u);
        int ulpv = findUParent(v);

        if(ulpu == ulpv)return;

        if(size[ulpu] > size[ulpv]){
            parent[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
        }

        else{
            parent[ulpu] = ulpv;
            size[ulpv] += size[ulpu];
        }
    }
};

    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraConnect=0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];

            if(ds.findUParent(u) == ds.findUParent(v)){
                extraConnect++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }

        // finding the number of connected components
        int connectComp=0;
        for(int i=0;i<n;i++){
            if(ds.findUParent(i) == i)connectComp++;
        }

        if(connectComp - 1 > extraConnect)return -1;

        return connectComp-1;
    }
};