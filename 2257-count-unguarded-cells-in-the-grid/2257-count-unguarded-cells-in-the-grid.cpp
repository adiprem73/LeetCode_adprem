class Solution {
public:
    int countUnguarded (int m, int n, vector<vector<int>> & guards, vector<vector<int>> & walls){
    swap(m,n);
    vector<vector<int>> vis(n, vector<int>(m,0));
    // let's mark all the cells which have guards or walls as visited
    for(auto it: guards){
        vis[it[0]][it[1]]=1;
    }
    for (auto it : walls)
    {
        vis[it[0]][it[1]] = 1;
    }
    // now each time we will be starting from a guard only
    vector<int> drow={-1,0,1,0};
    vector<int> dcol={0,1,0,-1};

    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m; ++j)
    //     {
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // cout<<endl;

    for(auto it: guards){
        int row= it[0];
        int col=it[1];
        for(int i=0;i<4;i++){
            int nrow= row+drow[i];
            int ncol= col+dcol[i];
            while(nrow>=0 && nrow<n && ncol>=0 && ncol<m&& vis[nrow][ncol]!=1){
                vis[nrow][ncol]=2;
                nrow = nrow + drow[i];
                ncol = ncol + dcol[i];
            }
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0){
                count++;
            }
        }
    }
    return count;

}
};