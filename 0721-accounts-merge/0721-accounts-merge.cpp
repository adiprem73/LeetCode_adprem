class Solution {

class DisjointSet{
    private:
    vector<int> parent, size;

    public:
    DisjointSet(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
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
        if(ulP_u == ulP_v) return;

        if(size[ulP_u] < size[ulP_v]){
            parent[ulP_u]= ulP_v;
            size[ulP_v]+= size[ulP_u];
        }
        else{
            parent[ulP_v]= ulP_u;
            size[ulP_u]+= size[ulP_v];
        }
    }
};


public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        DisjointSet ds(n+1);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            int size = accounts[i].size();
            for(int j=1;j<size;j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail]= i;
                } 
                else{
                    ds.unionBySize(i, mp[mail]);
                }               
            }
        }
        vector<string> mergedMail[n];
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