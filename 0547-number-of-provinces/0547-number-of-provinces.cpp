class Solution {
public:
    void dfs(int city, vector<int>& vis, vector<vector<int>> & isConnected){
        int n = isConnected.size();
        vis[city]=1; //visited marked
        for(int i=0;i<n;i++){
            if(isConnected[city][i] == 1 && vis[i] == 0){
                dfs(i, vis, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count=0;
        vector<int> vis(n);

        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                cout<<i<<endl;
                count++;
                dfs(i, vis, isConnected);
            }
        }
        return count;
    }
};