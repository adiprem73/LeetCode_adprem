class Solution {
public:
    bool dfs(int r, int c, int &m, int &n, string &curr, vector<vector<char>> &board, string word, vector<vector<int>>& vis){
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};

    vis[r][c] = 1;
    curr.push_back(board[r][c]);
    // cout<<curr<<endl;
    // base case
    if(curr==word){
        vis[r][c] = -1;
        curr.pop_back();
        return true;
    }

    // pruning
    if (curr != word.substr(0, curr.length()))
    {
        vis[r][c] = -1;
        curr.pop_back();
        return false;
    }

    for(int i=0;i<4;i++){
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(nr>=0 && nr<m && nc>=0 && nc<n){
            if(vis[nr][nc]==-1){
                
                if(dfs(nr, nc, m, n, curr, board, word, vis)){
                    vis[r][c] = -1;
                    curr.pop_back();
                    return true;
                }
                
            }
        }
    }

    // backtrack
    vis[r][c] = -1;
    curr.pop_back();

    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            vector<vector<int>> vis(m, vector<int>(n, -1));
            string curr = "";

            if(dfs(i, j, m, n, curr, board, word, vis)){
                return true;
            }
        }
    }
    return false;
    
}
};