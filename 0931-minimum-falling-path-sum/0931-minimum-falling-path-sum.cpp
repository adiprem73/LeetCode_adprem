class Solution {
public:
    int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> & dp){

    if(i==0) return matrix[i][j]; //base case


    if(dp[i][j]!=1e9)return dp[i][j]; //turne what already been computed to avoid any overlapping sums
    int up= (i>0)? func(i-1, j, matrix,dp) : 1e9;
    int upleft= (j>0)? func(i-1, j-1, matrix, dp) : 1e9;
    int upright= (i>0 && j+1< matrix.size())? func(i-1, j+1, matrix, dp) : 1e9;

    return dp[i][j] = min(up, min(upleft, upright))+ matrix[i][j];

}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n=matrix.size() ;
    int mini=INT_MAX;

    vector<vector<int>> dp(n, vector<int> (n, 1e9));
    //we need to call the function form every elelmnt of the last row
    for(int j=0;j<n;j++){
        mini=min(mini, func(n-1, j, matrix,dp));
    }
    return mini;     
}
};