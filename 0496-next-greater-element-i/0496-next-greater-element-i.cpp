class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // the very first task for me to do here would be to find the nge array fo nums2;
        stack<int> st;
        int n = nums2.size();
        vector<int> nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            if(st.empty()){
                nge[i]  = -1;
            }else{
                nge[i] = st.top();
            }

            st.push(nums2[i]);
        }

        vector<int> ans(nums1.size());
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums2[i]] = i;
        }

        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i]) != mp.end()){
                ans[i] = nge[mp[nums1[i]]];
            }else{
                ans[i] = -1;
            }
        }

        return ans;
    }
};