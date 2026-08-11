class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        st.push(asteroids[0]);
        for(int i=1;i<n;i++){
            while(!st.empty() && st.top()>0 && asteroids[i] <0){
                int ast1= st.top();
                int ast2 = asteroids[i]* -1;
                if(ast1 == ast2){
                    st.pop();
                    asteroids[i] =0;
                    break;
                }
                else if(ast1>ast2){
                    asteroids[i] =0;
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(asteroids[i] != 0){
                st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};