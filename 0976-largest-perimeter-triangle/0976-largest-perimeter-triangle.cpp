class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int maxi=0;
    for (int k = n - 1; k >= 2; k--)
    {
        int i=0;
        int j=k-1;
        while(i<j){
            if (nums[i] + nums[j] > nums[k])
            {
                maxi = max(maxi, nums[i] + nums[j] + nums[k]);
                
            }
            i++;
        }
        
    }
    return maxi;
}
};