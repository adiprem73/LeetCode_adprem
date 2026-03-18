class Solution {
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
{
    int m = grid.size();
    int n = grid[0].size();
    int cnt = 0;
    vector<vector<int>> preSum(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
                preSum[i][j]= grid[i][j];
                if(i>0){
                    preSum[i][j] += preSum[i-1][j];
                }
                if(j>0){
                    preSum[i][j] += preSum[i][j-1];
                }
                if(i>0 && j>0){
                    preSum[i][j] -= preSum[i-1][j-1];
                }
                if(preSum[i][j] <= k){
                    cnt++;
                }
            
        }
    }
    return cnt;
    
}
};