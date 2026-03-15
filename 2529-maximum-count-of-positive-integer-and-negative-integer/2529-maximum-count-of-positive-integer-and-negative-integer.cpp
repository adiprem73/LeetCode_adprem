class Solution {
public:
    int maximumCount(vector<int>& nums) {

    int n = nums.size();

    int l = 0, r = n-1;

    // first >=0
    while(l < r){
        int mid = l + (r-l)/2;
        if(nums[mid] < 0)
            l = mid + 1;
        else
            r = mid;
    }

    int negatives = (nums[l] < 0) ? l + 1 : l;

    l = 0, r = n-1;

    // first >0
    while(l < r){
        int mid = l + (r-l)/2;
        if(nums[mid] <= 0)
            l = mid + 1;
        else
            r = mid;
    }

    int positives = (nums[l] > 0) ? n - l : 0;

    return max(negatives, positives);
}
};