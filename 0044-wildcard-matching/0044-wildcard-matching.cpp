class Solution {
public:
   bool func(int i, int j, string s, string p, vector<vector<int>> dp){
    //base cases
    if(i<0 && j< 0)return true;
    if(i<0 && j>=0)return false;
    if(j<0 && i>=0){
        for(int x=0;x<=i;x++){
            if(p[x]!='*'){
                return false;
            }
        }return true;
    }

    //dp check
    if(dp[i][j]!=-1)return dp[i][j];

    //matching
    if(p[i]==s[j] || p[i]=='?'){
        return dp[i][j]=func(i-1, j-1, s, p,dp);
    }
    if(p[i]=='*'){
        return dp[i][j]=func(i-1, j, s, p,dp) || func(i, j-1, s, p,dp);
    }
    return false;
}

bool isMatch(string s, string p) {
    int n=p.size();
    int m=s.size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return func(n-1, m-1, s, p,dp); 
}
};