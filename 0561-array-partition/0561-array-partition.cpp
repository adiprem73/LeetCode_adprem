class Solution {
public:
    int arrayPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size() - 1; i = i + 2)
    {
        // cout<<nums[i]<<" "<<nums[i+1]<<endl;
        sum = sum+min(nums[i], nums[i + 1]);
    }
    return sum;
}
};