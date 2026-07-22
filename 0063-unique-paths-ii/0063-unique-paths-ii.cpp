class Solution {
public:
    int func(int r, int c, vector<vector<int>> &obstacleGrid, vector<vector<int>> & dp)
{
    // base cases
    if(r<0 || c<0){
        return 0;
    }
    if(r==0 && c==0 ){
        if(obstacleGrid[r][c]==0)return 1;
        else return 0;
    }
    if(obstacleGrid[r][c]==1){
        return 0;
    }

    if(dp[r][c] != -1){
        return dp[r][c];
    }

    int top =0, left =0;
    if(r-1>=0){
        if(obstacleGrid[r-1][c]==0){
            top = func(r-1, c, obstacleGrid, dp);
        }
    }
    if(c-1>=0){
        if(obstacleGrid[r][c-1] == 0){
            left = func(r, c-1, obstacleGrid, dp);
        }
    }
    return dp[r][c] = top + left;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n,-1));
    return func(m-1, n-1, obstacleGrid, dp);
}
};