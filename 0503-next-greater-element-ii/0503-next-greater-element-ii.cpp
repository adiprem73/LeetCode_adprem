class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        st.push(nums[(2*n-1)%n]);
        vector<int> nge(2*n);
        nge[2*n-1] = -1;
        for(int i=2*n-2;i>=0;i--){
            int ind = i%n;
            while(!st.empty() && nums[ind] >= st.top())st.pop();
            nge[i] = st.empty()? -1: st.top();

            st.push(nums[ind]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(nge[i]);
        }

        return ans;
    }
};