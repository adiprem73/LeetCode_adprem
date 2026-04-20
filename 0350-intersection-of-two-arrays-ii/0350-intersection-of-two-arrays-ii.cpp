class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> mp1,mp2;
    for(auto it: nums1){
        mp1[it]++;
    }
    for(auto it: nums2){
        mp2[it] ++;
    }

    vector<int> ans;
    for(auto it: mp1){
        if(mp2.count(it.first)>0){
            for(int i=0;i<min(it.second, mp2[it.first]);i++){
                ans.push_back(it.first);
            }
        }
    }
    return ans;
}

};