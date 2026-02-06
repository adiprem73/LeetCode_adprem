class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
    int n= nums.size();
    int i=0,j=0;
    int ans= n;
    sort(nums.begin(), nums.end());
    while(i<n){
        while(j<n && nums[j]<=1LL * k*nums[i]){
            j++;
        }
        ans= min(ans, n-(j-i));
        i++;
    }
    return ans;
}

};