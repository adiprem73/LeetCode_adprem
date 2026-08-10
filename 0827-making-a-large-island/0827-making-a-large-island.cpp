class Solution {

class DisjointSet{
    vector<int> parent, size;

    public:
    DisjointSet(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        size.resize(n, 1);
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
            parent[ulpv]= ulpu;
            size[ulpu]+= size[ulpv];
        }else{
            parent[ulpu]= ulpv;
            size[ulpv]+= size[ulpu];
        }
    }

    int getSize(int u){
        int ulpu = findUParent(u);
        return size[ulpu];
    }
};

int findNode(int r, int c, int n){
    return r*n + c;
}

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        bool hasZero =false;
        // make the disjoing set
        int Dsize = n*n +2;
        DisjointSet ds(Dsize);
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    for(int k=0;k<4;k++){
                        int nr = i+dr[k];
                        int nc = j+dc[k];
                        if(nr>=0 && nr<n && nc>=0 && nc<n){
                            if(grid[nr][nc] == 1){
                                int node = findNode(i,j,n);
                                int adjNode = findNode(nr,nc,n);
                                ds.unionBySize(node, adjNode);
                            }
                        }
                    }
                }
            }
        }

        // now the disjiong set is already done
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int currentSize =0;
                if(grid[i][j] == 0){
                    hasZero = true;
                    unordered_set<int> st;
                    for(int k=0;k<4;k++){
                        int nr = i+dr[k];
                        int nc = j+dc[k];
                        if(nr>=0 && nr<n && nc>=0 && nc<n){
                            if(grid[nr][nc] == 1){
                                int adjNode = findNode(nr,nc,n);
                                if(st.find(ds.findUParent(adjNode)) != st.end())continue;
                                st.insert(ds.findUParent(adjNode));
                                currentSize += ds.getSize(adjNode);
                            }
                        }
                    }
                }
                ans= max(ans, currentSize+1);
            }
        }
        if(!hasZero)return n*n;
        return ans;
    }
};