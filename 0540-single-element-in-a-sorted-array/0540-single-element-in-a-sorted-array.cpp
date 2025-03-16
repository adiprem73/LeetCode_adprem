class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

    int n=nums.size();

    //resolving the edge cases
    if(n==1)  return nums[0];
    if(nums[0]!=nums[1]){
        return nums[0];
    }
    if(nums[n-1]!=nums[n-2]){
        return nums[n-1];
    }

    int s=0,e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        // cout<<"hi";
        if(nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1]){
            return nums[mid];
        }


        //left side eleimination condition
        if(((mid%2==0)&&nums[mid]==nums[mid+1])||((mid%2==1)&&nums[mid]==nums[mid-1])){
            s=mid+1;
        }

        //right side elimination condition
        else{
            e=mid-1;
        }
    }
    return -1;


}
};