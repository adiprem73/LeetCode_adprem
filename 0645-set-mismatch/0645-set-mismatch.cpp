class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n= nums.size();
        map<int,int> mp;
        unordered_set<int> st;
        for(auto it: nums){
            mp[it]++;
            st.insert(it);
        }
        int extra, missing;
        for(auto it: mp){
            if(it.second==2){
                extra = it.first;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(st.count(i)==0){
                missing= i;
                break;
            }
        }
        return {extra, missing};
    }
};