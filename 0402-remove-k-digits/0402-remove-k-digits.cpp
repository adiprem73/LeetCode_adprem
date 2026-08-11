class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();

        if (k == n)
            return "0";

        stack<char> st;
        st.push(num[0]);

        for (int i = 1; i < n; i++) {
            char ch = num[i];

            while (!st.empty() && st.top() > ch && k > 0) {
                st.pop();
                k--;
            }

            st.push(ch);
        }

        // If k is still remaining, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // Remove leading zeroes
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        if (ans.empty())
            return "0";

        return ans;
    }
};