class Solution {
public:
    int minPathSum(vector<vector<int>> & grid){
    int n=grid.size();
    int m=grid[0].size();
    //observations: for computing the current element we only need the current row and the previous row

    vector<int> prev(m, 1e9);

    for(int i=0;i<n;i++){
        vector<int> curr(m,1e9);
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                curr[j]= grid[0][0];
                continue;
            }
            int left = (j>0)? curr[j-1] : 1e9;

            int up = (i>0)? prev[j] : 1e9;

            curr[j]= grid[i][j]+ min(left, up);
            
        }
        prev=curr;
    }
    return prev[m-1];
}
};