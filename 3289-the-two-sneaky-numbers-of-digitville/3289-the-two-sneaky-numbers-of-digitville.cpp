class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        set<int> seen;
        vector<int> duplicates;
        for(int i=0;i<nums.size();i++){
            if(seen.count(nums[i])){
                duplicates.push_back(nums[i]);
            }else{
                seen.insert(nums[i]);
            }
        }
        return duplicates;
    }
};