class Solution {
public:

class DisjointSet{
    private:
    vector<int> size, parent;

    public:
    DisjointSet(int n){
        size.resize(n, 0);
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

        if(size[ulpv] > size[ulpu]){
            parent[ulpu]=ulpv;
            size[ulpv]+= size[ulpu];
        }
        else{
            parent[ulpv]=ulpu;
            size[ulpu]+= size[ulpv];
        }
    }
};

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // we provide indexes to the entire thing. 
        // which means each accounts in accounts becomes a node
        // we will make a map data structure, in which we will put the emails with their node numbers. if an email comes which is like already in some other node, we will union the two nodes involved.
        // then attach the emails from the map to the parents of their nodes

        unordered_map<string,int> mp;
        int n = accounts.size();
        DisjointSet ds(n);


        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i;
                }else{
                    ds.unionBySize(i,mp[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> mergedMail(n);
        for(auto it: mp){
            string mail = it.first;
            int node = ds.findUParent(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;i++){
            if(mergedMail[i].size() == 0)continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};