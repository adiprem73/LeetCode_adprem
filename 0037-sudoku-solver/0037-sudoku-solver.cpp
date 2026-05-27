class Solution {
public:
    bool check(int row, int col, vector<vector<char>>& board){
    char val = board[row][col];
    // checking that row
    for(int i=0;i<9;i++){
        if(board[row][i] == val && i!=col){
            return false;
        }
        if(board[i][col] == val && i!=row){
            return false;
        }
    }
    // checkig subgrid
    int subgridRow = (row/3)*3;
    int subgridCol = (col/3)*3;

    for(int i=subgridRow;i<subgridRow+3;i++){
        for(int j=subgridCol;j<subgridCol+3;j++){
            if (board[i][j] == val && (i != row || j != col))
            {
                return false;
            }
        }
    }
    return true;
}

bool solvesSudoku(vector<vector<char>> &board)
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j] == '.'){
                for(char ch='1';ch<='9';ch++){
                    board[i][j]=ch;
                    if(check(i,j, board)){
                        if(solvesSudoku(board))return true;
                    }
                    // backtracking
                    board[i][j]='.';
                }
                return false;
            }
        }
    }   
    return true; 
}

void solveSudoku(vector<vector<char>>& board){
    solvesSudoku(board);
}

};