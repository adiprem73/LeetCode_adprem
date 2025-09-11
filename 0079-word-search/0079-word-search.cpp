class Solution {
public:
    bool func(int ind, int x, int y, vector<vector<char>> &board, string word)
{


    if (ind == word.size() - 1)
    {
        // cout << "executed" << endl;
        return true;
    }

    // to prevent same cell being counted twise we can mark the visited as '#'
    char temp = board[x][y];
    board[x][y]='#';


    int n = board.size();    // no. of rows
    int m = board[0].size(); // no. of columns
    // cout<<"no. of rows : "<<n<<endl;
    // cout<<"no. of cols : "<<m<<endl;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if (word[ind+1] == board[nx][ny])
            {
                if (func(ind + 1, nx, ny, board, word))
                {
                    board[x][y]= temp; // backtracking before returning
                    return true;
                }
            }
        }
    }
    board[x][y]= temp; //backtracking... 
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    bool flag;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {

            if (word[0] == board[i][j])
            {
                // cout << "x : " << i << endl
                //      << "y : " << j << endl;
                // cout<<"character is : "<<word[ind]<<endl;
                flag = func(0, i, j, board, word);
                if (flag == true)
                {
                    return flag;
                }
            }
        }
    }

    return flag;
}
};