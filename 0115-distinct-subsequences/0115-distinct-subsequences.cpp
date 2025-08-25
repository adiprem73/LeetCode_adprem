class Solution {
public:
    
int numDistinct(string s, string t) {
    int n=s.size();
    int m=t.size();
    vector<vector<long long>> dp(n+1, vector<long long> (m+1,0)); //now the indexing is all one based inside the dp table
    //i think we might want to shift the dp table by one index

    for(int i=0;i<=n;i++){ //i think this will solve the base case number 1 and base case number 2 isnt necessary since alreayd all the elements inside the dp table are initialised with 0
        dp[i][0]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = ( (__int128)dp[i-1][j-1] + dp[i-1][j] );
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}
};