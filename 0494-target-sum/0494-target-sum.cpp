class Solution {
public:
int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size();
    int totalSum=accumulate(nums.begin(), nums.end(),0);

    if(abs(target)>totalSum) return 0;
    vector<vector<int>> dp(n, vector<int>(2* totalSum + 1, -1));

    for(int j=-totalSum ; j<=totalSum ; j++){
        if (nums[0]==0 && j==0) dp[0][j+totalSum]=2;
        else if (j==nums[0] || j==-nums[0]) dp[0][j+totalSum]=1;
        else dp[0][j+ totalSum] = 0;
    }
    

    for(int i=1;i<n;i++){
        for(int j=-totalSum;j<=totalSum;j++){
            int plus=(j-nums[i] >= -totalSum)? dp[i-1][j- nums[i]+totalSum] : 0;

            int minus=(j+nums[i] <= totalSum)? dp[i-1][j+ nums[i]+totalSum] : 0;

            dp[i][j+totalSum]=plus + minus;
        }
    }

    return dp[n-1][target+totalSum];

}
};