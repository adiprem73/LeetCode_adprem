class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set2(nums2.begin(), nums2.end());
        int mn= INT_MAX;
        for(auto it: nums1){
            if(set2.count(it)>0){
                return it;
            }
        }
        return -1;
    }
};