class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>&vis, vector<vector<char>>& board){
        vis[r][c]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            // check constraint
            if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 && board[nr][nc]=='O'){
                dfs(nr, nc, vis, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int> (n,0));
        // i just need to call all the boundary elelments into dfs
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j ==0 || i==m-1 || j==n-1){
                    if(board[i][j]=='O' && vis[i][j]==0){
                        dfs(i, j, vis, board);
                    }
                }
            }
        }
        for(auto row: vis){
            for(auto it: row){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};