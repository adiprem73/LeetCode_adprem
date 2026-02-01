class Solution {
public:
    int minimumCost (vector<int>& nums){
    int a= nums[0];
    int i1,mn1=INT_MAX;
    for(int i=1;i<nums.size();i++){
        if(nums[i]<mn1){
            i1= i;
            mn1=nums[i];
        }
    }
    int mn2= INT_MAX;
    for(int i=1;i<nums.size();i++){
        if(nums[i]<mn2 && i!= i1){
            mn2= nums[i];
        }
    }
    return a+mn1+mn2;

}
};