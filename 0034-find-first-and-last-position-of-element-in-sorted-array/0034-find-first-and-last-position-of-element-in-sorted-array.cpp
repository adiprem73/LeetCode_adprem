class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target)
{
    int n= nums.size();
    int ind = -1;
    for(int i=0;i<n;i++){
        if(nums[i] == target){
            ind = i;
            break;
        }
    }
    int ind2 = -1;
    for(int i= n-1;i>=0;i--){
        if(nums[i] == target){
            ind2 = i;
            break;
        }
    }
    return {ind, ind2};
}
};