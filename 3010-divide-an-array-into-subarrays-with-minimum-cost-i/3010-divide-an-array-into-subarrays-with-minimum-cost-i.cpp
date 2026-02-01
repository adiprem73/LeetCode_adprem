class Solution {
public:
    int minimumCost(vector<int>& nums){
    int a= nums[0];
    int mn1 = INT_MAX, mn2= INT_MAX;

    for(int i=1;i<nums.size();i++){
        if(nums[i]<mn1){
            mn2= mn1;
            mn1 = nums[i];
        }else if(nums[i]< mn2){
            mn2 = nums[i];
        }
    }
    return a+ mn1+mn2;
}
};