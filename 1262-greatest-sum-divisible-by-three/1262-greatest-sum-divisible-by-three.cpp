class Solution {
public:
    int func(int pos, vector<int> &nums, int n, vector<vector<int>> &dp, int rem)
{
    if(pos==n){
        return (rem==0)? 0: INT_MIN/2;
    }

    if(dp[pos][rem] !=-1){
        return dp[pos][rem];
    }

    int pick=  nums[pos] + func(pos+1, nums, n, dp, (rem+nums[pos])%3);

    int notPick = func(pos+1, nums,n , dp, rem);

    // cout<<"index : "<<pos<<" "<<pick<<" "<<notPick<<endl;
    return dp[pos][rem] = max(pick, notPick);
}

int maxSumDivThree(vector<int>& nums) {
    int n= nums.size();

    vector<vector<int>> dp(n, vector<int>(3, -1));
    return func(0, nums, n, dp, 0);
}
};