class Solution {
public:
    static bool comp(int a, int b){
    if(a>b)return true;
    return false;
}

int largestPerimeter(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), comp);
    int n=nums.size();

    for(int i=0;i<n-2;i++){
        if(nums[i]<nums[i+1]+nums[i+2]){
            return (nums[i]+nums[i+1]+nums[i+2]);
        }
    }return 0;
}
};