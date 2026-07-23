class Solution {
public:
    int func(int row, int ind, vector<vector<int>> &triangle, vector<vector<int>>& dp)
{
    // base case
    if(row == 0){
        return triangle[0][0];
    }

    // dp check 
    if(dp[row][ind]!=-1){
        return dp[row][ind];
    }

    int sizeOfRow = triangle[row].size();
    int score = INT_MAX;
    if(ind == 0){
        score = min(score, triangle[row][0] + func(row-1, 0, triangle , dp));
    }else if(ind == sizeOfRow-1){
        score = min(score, triangle[row][ind] + func(row - 1, ind - 1, triangle, dp));
    }else{
        score = min(score, triangle[row][ind] + func(row - 1, ind - 1, triangle, dp));
        score = min(score, triangle[row][ind] + func(row - 1, ind, triangle, dp));
    }

    return dp[row][ind] = score;
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    int size = triangle[n-1].size();

    vector<vector<int>> dp(n, vector<int>(size, -1));
    int ans = INT_MAX;

    for(int i=0;i<size;i++){
        ans = min(ans, func(n-1, i, triangle, dp));
    }
    return ans;
}
};