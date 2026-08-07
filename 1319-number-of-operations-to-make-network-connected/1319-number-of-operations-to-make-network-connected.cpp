class Solution {
public:
    class DisjointSet{
        vector<int> parent, size;
        public:
        DisjointSet(int V){
            size.resize(V+1, 1);
            parent.resize(V+1);
            for(int i=0;i<=V;i++){
                parent[i] = i;
            }
        }

        int findUPar(int u){
            if(parent[u] == u)return u;
            return parent[u] = findUPar(parent[u]);
        }

        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v)return;
            
            if(size[ulp_v]>size[ulp_u]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
    };

    // the basic idea behind this question is that, the number of connections requried to make evetrhting connected is (numOfConnectedComponents - 1).
    // so, using DSU we will find the number of extra connections(those whicha re nore required). we will also find the number of connectedomcpoennts. and then we can declare the answer

    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        // to find the number of extra components
        int extraConnections=0;
        for(auto it: connections){
            int u= it[0];
            int v= it[1];
            if(ds.findUPar(u) == ds.findUPar(v)){
                extraConnections++;
            }else{
                ds.unionBySize(u,v);
            }
        }     
        int connectedComponentsCount=0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i) == i){
                connectedComponentsCount++;
            }
        }

        return (connectedComponentsCount - 1) <= extraConnections ? connectedComponentsCount - 1 : -1;
    }
};