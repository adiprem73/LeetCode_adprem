class Solution {
public:
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int, int> mp; // Map to store the last index of each element
    for (int i = 0; i < nums.size(); i++) {
        if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k) {
            return true; // Found a duplicate within the range k
        }
        mp[nums[i]] = i; // Update the last index of the current element
    }
    return false; // No duplicates found within the range k
        
}
};