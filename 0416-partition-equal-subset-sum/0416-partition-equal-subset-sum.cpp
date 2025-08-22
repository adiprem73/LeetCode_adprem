class Solution {
public:
    bool canPartition(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    for(auto it: nums){
        sum+=it;
    }    
    if(sum%2!=0)return false; 

    vector<vector<int>> dp(n, vector<int>(sum/2 +1, -1));

    for(int i=0;i<n;i++) dp[i][0]=1;

    for(int i=0;i<sum/2+1;i++) dp[0][i]=( nums[0]==i);

    for(int i=1;i<n;i++){
        for(int j=1;j<sum/2+1;j++){
            bool notPick = dp[i-1][j];

            bool pick=false;
            if(nums[i]<= j){
                pick= dp[i-1][j-nums[i]];
            }

            dp[i][j]= pick||notPick;
        }
    }
    return dp[n-1][sum/2];


}
};