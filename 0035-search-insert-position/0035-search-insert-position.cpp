class Solution {
public:
    int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    int s =0;
    int e= n;
    while(s < e){
        int mid = s+(e-s)/2;
        if(nums[mid]>=target)e=mid;
        else s=mid+1;
    }
    return s;
}
};