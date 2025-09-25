class Solution {
public:

bool chechHash(vector<int> nums){
    for(int i=0;i<9;i++){
        if(nums[i]>1){
            return false;
        }
    }return true;
}
    bool isValidSudoku(vector<vector<char>> &board)
{
    // row and column check
    vector<int> row(9);
    for(int i=0;i<9;i++){
        vector<int> row(9);
        for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
                row[board[i][j]-'0'-1]++;
            }
            
        }
        if(chechHash(row)==false){
            return false;
        }
        vector<int> col(9);
        for(int j=0;j<9;j++){
            if(board[j][i]!='.'){
                col[board[j][i] - '0'-1]++;
            }
            
        }
        if(chechHash(col)== false){
            return false;
        }
    }

    for(int k=0;k<=6;k=k+3){
        for(int l=0;l<=6;l=l+3){
            vector<int> hash(9);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i+k][j+l]!='.'){
                    hash[board[i + k][j + l] - '0'-1]++;
                }
            }
        }
        if(chechHash(hash)==false){
            return false;
        }
        }
        
    }
    return true;
}
};