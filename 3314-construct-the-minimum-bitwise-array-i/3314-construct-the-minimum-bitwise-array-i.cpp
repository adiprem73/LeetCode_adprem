class Solution {
public:
    vector<int> minBitwiseArray(vector<int> &nums)
{
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        // cout <<"nums[i] : "<< nums[i] << endl;
        if (nums[i] == 2)
        {
            ans[i] = -1;
            continue;
        }
        
        
        for (int j = 1; j < nums[i]; j++)
        {
            // cout<<"j :"<<j<<endl;
            if ((j | (j + 1)) == nums[i])
            {
                // cout<<"hello"<<endl;
                ans[i] = j;
                break;
            }
        }
        // cout<<endl;
    }
    return ans;
}
};