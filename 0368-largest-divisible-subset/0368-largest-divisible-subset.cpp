class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,1), hash(n);
    
    int maxi=INT_MIN;
    int lastIndex=0;
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if(nums[i] % nums[prev]==0 && dp[i] < 1+dp[prev]){
                dp[i]=1+dp[prev];
                hash[i]= prev;
            }
        }
        if(dp[i] > maxi){
            maxi=dp[i];
            lastIndex=i;
        }
    }
    vector<int> lis;
    lis.push_back(nums[lastIndex]);
    int ind=1;
    while(hash[lastIndex]!=lastIndex){
        lastIndex= hash[lastIndex];
        lis.push_back(nums[lastIndex]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}
};