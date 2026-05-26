class Solution {
public:
    bool isValid(int row, int col, vector<string> &board, int n)
{

    // upper left diagonal
    int i = row, j = col;

    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;

        i--;
        j--;
    }

    // upper right diagonal
    i = row;
    j = col;

    while (i >= 0 && j < n)
    {
        if (board[i][j] == 'Q')
            return false;

        i--;
        j++;
    }

    // same column
    i = row;

    while (i >= 0)
    {
        if (board[i][col] == 'Q')
            return false;

        i--;
    }

    return true;
}

void func(int row, vector<string> & board, vector<vector<string>> & ans, int & n){
    // base case
    if(row == n){
        ans.push_back(board);
        for(auto it: board){
            cout<<it<<endl;
        }
        return;
    }

    for(int i=0;i<n;i++){ // trying for each col
        
        if(isValid(row, i, board, n)){
            board[row][i] = 'Q';
            func(row+1, board, ans, n);
        }
        // backtracking
        board[row][i] = '.';
    }
}

vector<vector<string>> solveNQueens(int n)
{
    string st(n,'.');
    vector<string> board(n, st);
    vector<vector<string>> ans;
    func(0, board, ans, n);
    return ans;
}
};