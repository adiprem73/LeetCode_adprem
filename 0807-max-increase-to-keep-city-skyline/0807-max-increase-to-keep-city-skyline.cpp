class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<int> rows(n);
    vector<int> cols(n);
    for (int i = 0; i < n; i++)
    {
        int mx = 0;
        for (int j = 0; j < n; j++)
        {
            mx = max(mx, grid[i][j]);
        }
        rows[i] = mx;
    }
    for (int i = 0; i < n; i++)
    {
        int mx = 0;
        for (int j = 0; j < n; j++)
        {
            mx = max(mx, grid[j][i]);
        }
        cols[i] = mx;
    }
    // vprint(rows);
    // vprint(cols);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans+= (min(rows[i] , cols[j])) - grid[i][j] ;
        }
    }
    return ans;
}
};