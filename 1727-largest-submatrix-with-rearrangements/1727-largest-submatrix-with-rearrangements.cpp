class Solution {
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> ones(m, vector<int>(n));
    for(int c=0;c<n;c++){
        int sum=0;
        for(int r=0;r<m;r++){
            if(matrix[r][c]==1){
                sum++;
            }
            else{
                sum=0;
            }
            ones[r][c]=sum;
        }
    }
    int ans = 0;

    for (int r = 0; r < m; r++)
    {
        vector<int> temp = ones[r];

        sort(temp.begin(), temp.end(), greater<int>()); // descending

        for (int c = 0; c < n; c++)
        {
            int height = temp[c];
            int width = c + 1;
            ans = max(ans, height * width);
        }
    }

    return ans;
}
};