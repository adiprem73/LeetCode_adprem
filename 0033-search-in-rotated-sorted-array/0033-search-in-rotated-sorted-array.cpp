class Solution {
public:
    int search(vector<int>& nums, int target) {
    int n = nums.size();
    int k=0;
    for(int i=0;i<n-1;i++){
        if(nums[i+1]<nums[i])k=i;
    }       
    int s=0;
    int e = k;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(nums[mid]==target)return mid;
        else if(nums[mid]<target)s=mid+1;
        else e=mid-1;
    }
    s=k+1;
    e=n-1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}
};