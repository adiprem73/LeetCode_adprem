class Solution {
public:
    int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int s =0;
    int e = n-1;
    if(n==1)return nums[0];
    if(nums[0]!=nums[1])return nums[0];
    if(nums[n-1]!=nums[n-2])return nums[n-1];
    while(s<=e){
        int mid = s+(e-s)/2;
        if(  nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
            return nums[mid];
        }
        else if(mid+1<n &&  nums[mid]==nums[mid+1]){
            if(mid%2==0){ // 1st occurrence is even
                s=mid + 1;
            }else{ // 1st occurrence is odd
                e=mid - 1;
            }
        }
        else{
            if(mid%2==0){ //2nd occurrence is even
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
    }
    return 0;
}
};