class Solution {
public:
    int minAdjacentSwaps(vector<int> &nums, int a, int b)
{
    long long m = 1e9+7;
    long long ans =0;
    int n = nums.size();
    int p=0;

    for(int i=0;i<n;i++){
        if(nums[i]<a){
            ans+= i-p; p++;
        }
    }

    p=n-1;
    int ex =0;
    for(int i=n-1;i>=0;i--){
        if(nums[i]<a){
            ex++;
        }else if(nums[i] > b){
            ans+=p-i-ex;
            p--;
        }
    }
    ans = ans%m;
    return ans;
}

};