class Solution {
public:
    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<char>>& board){
    int m = board.size();
    int n = board[0].size();
    vis[x][y]=1; // makr them visited
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0,1,0,-1};
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny]==0 && board[nx][ny]=='O'){
            dfs(nx, ny, vis, board);
        }
    }
}

void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    
    vector<vector<int>> vis(m, vector<int>(n, 0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==m-1 || j==0 || j==n-1){
                if(board[i][j]=='O'){
                    cout<<"hello"<<endl;
                    dfs(i,j, vis, board);
                }
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<vector<char>> ans(m, vector<char>(n, 'X'));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='O' && vis[i][j] == 0){
                board[i][j] = 'X';
            }
        }
    }
}
};