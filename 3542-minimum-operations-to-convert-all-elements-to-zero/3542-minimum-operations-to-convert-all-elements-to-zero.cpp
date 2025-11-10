class Solution {
public:
    int minOperations(vector<int> &nums){
    stack<int> st;
    int cnt=0;
    for(auto it: nums){
        
            while( !st.empty() && it<st.top()){
                st.pop();
            }
        
        if(it==0)continue;
        
        if(st.empty() || st.top() <it){
            cnt++;
            st.push(it);
        }
    }
    return cnt;
}
};