class Solution {
public:
    int minOperations(vector<int> &nums)
{
    int n= nums.size();
    
    // if there are ones already present inside the arrray
    int ones=0;
    for(auto it: nums){
        if (it==1){
            ones++;
        }
    }
    if(ones) return n-ones;

    // if gcd of the entire array is greater thatn 1 then also its impossible to convert the entire array into 1
    int overallgcd=0;
    for(auto it: nums){
        overallgcd= gcd(overallgcd, it);
    }
    if(overallgcd!=1)return -1;

    // since now we confirm that the arrays overall gcd is not equal to 1 we can easily find the shorted lenght whose gcd is equal to 1

    int bestlen= INT_MAX;

    for(int i=0;i<n;i++){
        int g=0;
        for(int j=i;j<n;j++){
            g= gcd(g, nums[j]);
            if(g==1){
                bestlen= min(bestlen, j-i+1);
            }
        }
    }
    // cout<<bestlen;
    return n+bestlen-2;
}
};