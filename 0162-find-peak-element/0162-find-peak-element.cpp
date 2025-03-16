class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        sort(nums.begin(),nums.end());
        return mp[nums[nums.size()-1]];
    }
};