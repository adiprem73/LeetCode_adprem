class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
    int n=triangle.size();// number of rowas
    // vector<vector<int>> dp(n, vector<int>(n,1e9));
    vector<int> prev(n);
    prev= triangle[n-1]; //take the lat row of the triangle only

    // now since we went top to bottom in recursion and in memo,w e will do the opposite in tabulation. in tabulation we always want to start with some wehre thatt we alreayd inow tha vlaue know

    // in this case, we already know that the last row will have itself as the dp wehn we start at bottom

    // setting the last row of dp ss the same as the last row of triangle grid
    for(int i=n-2;i>=0;i--){


        vector<int> curr(i+1,0); //to store the current array
        for(int j=0;j<=i;j++){
            // dp[i][j]= min(dp[i+1][j], dp[i+1][j+1])+ triangle[i][j];
            curr[j]= min(prev[j], prev[j+1])+ triangle[i][j];
        }

        // vprint(prev);
        // vprint(curr);
        // cout<<endl;
        prev=curr;
    }

    return prev[0];
}
};