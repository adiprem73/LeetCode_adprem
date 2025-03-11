class Solution {
public:
    int searchInsert(vector<int>& nums, int target){
        int n=nums.size();
        int s=0;
        int e=n-1;
        // bool flag=false;
        while(s<=e){
            int mid=(s+e)/2;
            
            if(nums[mid]==target){
                // flag=true;
                return mid;
            }
            else  if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        // if(flag==false){
        //     int i;
        //     for(i=0;nums[i]<=target;i++){


        //     }
        //     return i;
        // }
        return s;
    }
};