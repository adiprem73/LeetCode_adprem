class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // find the nse and the pse

        // findingg the pse
        stack<int> st;
        int n = heights.size();
        if (n == 1)
            return heights[0];
        vector<int> nse(n), pse(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        st = {};
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {

            int l = pse[i];
            int r = nse[i];

            if (r == -1)
                r = n;

            int width = r - l - 1;

            ans = max(ans, width * heights[i]);
        }
        return ans;
    }
};