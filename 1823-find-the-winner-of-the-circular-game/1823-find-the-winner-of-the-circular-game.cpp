class Solution {
public:
    int findTheWinner(int n, int k)
{
    vector<int> nums;
    for (int i = 1; i <= n; i++)
    {
        nums.push_back(i);
    }
    int curr =0 ;
    while (nums.size() != 1)
    {
        int size = nums.size();
        int ind = (curr+k - 1) % size;
        nums.erase(nums.begin() + ind);
        curr= ind;
        // vprint(nums);
    }

    return nums[0];
}
};