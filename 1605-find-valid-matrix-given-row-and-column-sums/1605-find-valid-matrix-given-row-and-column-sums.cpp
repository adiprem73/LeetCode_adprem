class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
{
    int m = rowSum.size();
    int n = colSum.size();
    vector<vector<int>> ans(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ans[i][j]= min(rowSum[i], colSum[j]);
            rowSum[i]-= ans[i][j];
            colSum[j]-= ans[i][j];
            // cout<<"row sum : "<<endl;
            // vprint(rowSum);
            // cout<<"col sum : "<<endl;
            // vprint(colSum);
            // cout<<endl;
        }
    }
    return ans;
}
};