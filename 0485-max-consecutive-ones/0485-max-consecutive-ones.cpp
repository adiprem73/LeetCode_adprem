class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int count=0;
    int maxCount=0;
    bool flag=false;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            flag=true;
            count++;
        }
        else{
            flag = false;
            count=0;
        }


        if(count>maxCount){
            maxCount=count;
        }
    } 
    return maxCount;
}
};