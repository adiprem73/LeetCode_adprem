class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1,mp2;
        for(auto it: nums1){
            mp1[it]++;
        }
        for(auto it: nums2){
            mp2[it]++;
        }

        int answer1=0, answer2=0;
        for(auto it: nums1){
            if(mp2.count(it)>0)answer1++;
        }
        for(auto it: nums2){
            if(mp1.count(it)>0)answer2++;
        }
        return {answer1, answer2};
    }
};