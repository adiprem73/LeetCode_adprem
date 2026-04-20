class Solution {
public:
    int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    for(int i=0;i<n;i++){
        int s = i+1;
        int e = n-1;
        int target = nums[i];
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target){
                return target;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
    }
    return 0;
}
};