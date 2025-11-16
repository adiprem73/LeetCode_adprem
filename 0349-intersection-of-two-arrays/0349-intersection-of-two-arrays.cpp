class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        for(int i=0;i<nums1.size();i++){
            st.insert(nums1[i]);
        }
        set<int> st2;
        for(int i=0;i<nums2.size();i++){
            if(st.count(nums2[i])){
                st2.insert(nums2[i]);
            }
        }
        vector<int> ans(st2.begin(), st2.end());
        return ans;
    }
};