class Solution {
public:
    int maxRotateFunction(vector<int> &nums)
{
    int n = nums.size();
    int sum1=0, totalSum=0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum+=nums[i];
        sum1 += i*(nums[i]);
    }
    // cout<<sum1<<endl;
    // cout<<totalSum<<endl;
    ans = sum1;
    for(int i=1;i<n;i++){
        // cout<<sum1 <<" + "<< totalSum<< " - ("<<n<<" * "<<"nums["<<n-i<<"])"<<endl;
        sum1 = sum1 + (totalSum - n*nums[n-i]);
        // cout<<sum1<<endl;
        ans = max(ans, sum1);
    }
    return ans;
}
};