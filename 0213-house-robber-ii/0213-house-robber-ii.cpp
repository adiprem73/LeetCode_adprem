class Solution {
public:
    int rob(vector<int>& nums) {
    int n=nums.size();
    // vector<int> dp(n, -1);
    // dp[0]= nums[0];

    if(n == 1) return nums[0];
    if(n==2) return max(nums[0], nums[1]);

    int prev2= nums[0];
    int prev1= max(nums[0], nums[1]); //if htere are only two hosues, the robber will ofcourse loot the one witht he most loot
    for(int i=2;i<n-1;i++){
        int pick = nums[i]+ prev2;

        int notpick = prev1;

        int curr = max(pick, notpick);

        prev2= prev1;
        prev1 = curr;
    }
    //prev1 is the ans1 whcih excludes the last element
    int ans1= prev1;

    prev2= nums[1];
    prev1= max(nums[1], nums[2]); //if htere are only two hosues, the robber will ofcourse loot the one witht he most loot
    for(int i=3;i<n;i++){
        int pick = nums[i]+ prev2;

        int notpick = prev1;

        int curr = max(pick, notpick);

        prev2= prev1;
        prev1 = curr;
    }
    // prev1 here is the ans2 which excludes the first element
    int ans2= prev1;


    return max(ans1, ans2);


}
};