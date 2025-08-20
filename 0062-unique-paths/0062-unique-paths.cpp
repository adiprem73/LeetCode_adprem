class Solution {
public:
    int uniquePaths(int m, int n){
    vector<int> dp(n, 0);
    dp[0] = 1;  // base case

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(j > 0){
                dp[j] = dp[j] + dp[j-1]; // current cell = from top (dp[j]) + from left (dp[j-1])
            }
            // if j==0, dp[j] stays same (only from top, which is already dp[j])
        }
    }

    return dp[n-1];
}

};