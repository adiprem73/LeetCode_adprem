class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st; //mono-tonic stack
        int n = nums2.size();
        vector<int> nge(n);
        st.push(nums2[n-1]);
        nge[n-1]=-1;
        unordered_map<int,int> mp;
        mp[nums2[n-1]]= n-1;
        for(int i=n-2;i>=0;i--){
            mp[nums2[i]] = i;
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }
            nge[i] = st.empty()? -1: st.top();
            st.push(nums2[i]);
        }
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i] = nge[mp[nums1[i]]];
        }
        return ans;
    }
};