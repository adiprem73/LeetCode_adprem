class Solution {
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
{
    int n = nums.size();
    for(int i=0;i<k;i++){
        int min=INT_MAX;
        int ind;
        for(int j=0;j<n;j++){
            if(min>nums[j]){
                min= nums[j];
                ind =j;
            }
        }
        nums[ind]*= multiplier;
    }
    return nums;
}
};