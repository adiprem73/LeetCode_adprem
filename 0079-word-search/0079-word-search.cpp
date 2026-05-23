class Solution {
public:
    bool dfs(int r, int c, int ind, vector<vector<char>>& board, string &word, vector<vector<int>>& vis){
    vis[r][c]= 1;

    int m = board.size();
    int n = board[0].size();
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    // base cases
    if(ind == word.size()-1){
        vis[r][c] = -1; // backtracking
        return true;
    }

    for(int i=0;i<4;i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==-1 && board[nr][nc] == word[ind+1]){
            
            if(dfs(nr, nc, ind+1, board, word, vis)){
                vis[r][c] = -1; // backtracking
                return true;
            }

            // 
        }
    }

    // backtracking
    vis[r][c]=-1;

    return false;
}


bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            vector<vector<int>> vis(m, vector<int>(n, -1));

            if(word[0] == board[i][j]){
                if(dfs(i, j, 0, board, word, vis)){
                    return true;
                }
            }
        }
    }
    return false;
    
}
};