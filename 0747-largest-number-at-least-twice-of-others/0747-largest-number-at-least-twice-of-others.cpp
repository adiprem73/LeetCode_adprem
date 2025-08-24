class Solution {
public:
    int dominantIndex(vector<int>& nums) {
    int maxi=0;
    int maxiInd=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>maxi){
            maxi=nums[i];
            maxiInd=i;
        }
    }
    sort(nums.begin(), nums.end());
    int largestNum=nums[nums.size()-1];
    int secondLargestNum=nums[nums.size()-2];
    bool flag= false;
    if(largestNum>= 2*secondLargestNum){
        return maxiInd;
    }  return -1;
}
};