class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n){
    int duprow=row;
    int dupcol=col;

    // so checking is only must in three directions: NW, W and SW

    // 1. checking diagonlly upwards: NW
    while(duprow>=0 && dupcol>=0){
        if(board[duprow][dupcol]=='Q'){
            return false;
        }
        duprow--;
        dupcol--;
    }

    // 2. checking left side: W
    dupcol=col;
    duprow=row;
    while(dupcol>=0){
        if (board[duprow][dupcol] == 'Q')
        {
            return false;
        }
        dupcol--;
    }

    // 3. checking right side: SW
    dupcol = col;
    duprow = row;
    while(duprow<n && dupcol>=0){
        if (board[duprow][dupcol] == 'Q')
        {
            return false;
        }
        dupcol--;
        duprow++;
    }

    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    //base case
    if(col==n){
        ans.push_back(board);
        return;
    }

    // trying out every row
    for(int row=0;row<n;row++){
        if(isSafe(row, col, board, n)){ // this function will simply check if tis safe to place the queen there or not
            board[row][col]='Q';
            solve(col+1, board, ans, n);
            board[row][col]= '.';    // backtracking...         
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    solve(0, board, ans, n);
    return ans;
}
};