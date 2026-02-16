class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>> & visit){
    // makr this row as visited
    visit[i][j]= true;
    int m = board.size();
    int n = board[0].size();

    // we need to move/ check in four directions 
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for(int k=0;k<4;k++){
        int nx = i +dx[k];
        int ny = j + dy[k];
        if(nx>=0 && nx<m && ny>=0 && ny <n && visit[nx][ny]==false && board[nx][ny]=='X'){
            dfs(nx, ny, board, visit);
        }
    }
}

int countBattleships(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();

    vector<vector<bool>> visit(m, vector<bool>(n, false)); // this will serve as the visited array
    int cnt=0; // this will be used to count the final answer

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]== 'X' && visit[i][j]== false){
                // if we find an x we will call the dfs from this cell
                dfs(i, j, board, visit);
                cnt++;
            }
        }
    }
    return cnt;
}
};