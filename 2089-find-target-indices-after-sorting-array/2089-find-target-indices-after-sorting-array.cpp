class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

    sort(nums.begin(), nums.end());
    int n = nums.size();

    int l = 0, r = n-1;

    // lower bound
    while(l < r){
        int mid = l + (r-l)/2;
        if(nums[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }

    if(nums[l] != target)
        return {};

    int lower = l;

    l = 0, r = n-1;

    // upper bound
    while(l < r){
        int mid = l + (r-l)/2 + 1;
        if(nums[mid] > target)
            r = mid - 1;
        else
            l = mid;
    }

    int upper = l;

    vector<int> ans;
    for(int i = lower; i <= upper; i++)
        ans.push_back(i);

    return ans;
}
};