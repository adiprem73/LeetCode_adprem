class Solution {
public:

    // this question can be solved by seeing the coordinates as nodes of a graph. and we will have to form edges between the co-oridinates which share same row or same column
    class DisjointSet{
        private: 
        vector<int> parent, size;
        public:
        DisjointSet(int n){
            parent.resize(n+1);
            for(int i=0;i<n+1;i++){
                parent[i] = i;
            }
            size.resize(n+1, 1);
        }

        int findUParent(int u){
            if(parent[u] == u)return u;

            return parent[u] = findUParent(parent[u]);
        }

        void unionBySize(int u, int v){
            int ulP_u = findUParent(u);
            int ulP_v = findUParent(v);

            if(ulP_u == ulP_v)return; // already connected to the same components

            if(size[ulP_v]>size[ulP_u]){
                parent[ulP_u]= ulP_v;
                size[ulP_v] += size[ulP_u];
            }

            else{
                parent[ulP_v]= ulP_u;
                size[ulP_u] += size[ulP_v];
            }
        }
    };

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n);
        int maxRow =0;
        int maxCol =0;

        for(auto it: stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int> stoneNodes;
        for(auto it: stones){
            int u = it[0];
            int v = it[1] + maxRow + 1;
            ds.unionBySize(u,v);
            stoneNodes[u] = 1;
            stoneNodes[v]= 1;
        }
        int cnt =0;
        for(auto it: stoneNodes){
            if(ds.findUParent(it.first) == it.first){
                cnt++;
            }
        }

        return n - cnt;
    }
};