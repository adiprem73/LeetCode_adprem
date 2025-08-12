class Solution {
public:
    void dfs(int r, int c, vector<vector<char>> &board, vector<vector<int>> &vis)
{
    vis[r][c] = 1;
    int n = board.size();
    int m = board[0].size();
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = r + drow[i];
        int ncol = c + dcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && vis[nrow][ncol] != 1)
        {
            dfs(nrow, ncol, board, vis);
        }
    }
}

void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // only run for boundary conditions
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                if (board[i][j] == 'O' && vis[i][j] != 1)
                {
                    dfs(i, j, board, vis);
                }
            }
        }
    }
    vector<vector<char>> ans(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==1){
                ans[i][j]='O';
            }
            else{
                ans[i][j]='X';
            }
        }
    }
    board=ans;
}
};