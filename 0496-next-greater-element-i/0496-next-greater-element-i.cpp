class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        vector<int> nextGreater(n);
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty()){
                if(st.top()<=nums2[i]){
                    st.pop();
                }else{
                    break;
                }
            }
            if(!st.empty()){
                nextGreater[i]= st.top();
            }else{
                nextGreater[i]= -1;
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<n;j++){
                if(nums1[i] == nums2[j]){
                    ans.push_back(nextGreater[j]);
                }
            }
        }
        return ans;
    }
};