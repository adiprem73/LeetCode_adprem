class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    set<int> s;
    for(int i=0;i<nums.size();i++){
        if(s.find(nums[i])!= s.end()){
            return true; // Duplicate found
        }
        s.insert(nums[i]); // Insert the number into the set

    }
    return false;
    }


};