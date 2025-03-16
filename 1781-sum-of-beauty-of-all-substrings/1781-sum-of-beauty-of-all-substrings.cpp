class Solution {
public:
    int beautySum(string s) {
    int ans = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        int freq[26] = {0}; // Initialize frequency array for each starting index i

        for (int j = i; j < n; j++) {
            char ch = s[j];
            freq[ch - 'a']++; // Update frequency of the current character

            int mx = INT_MIN;
            int mn = INT_MAX;

            // Calculate max and min frequency in the current substring
            for (int k = 0; k < 26; k++) {
                if (freq[k] > 0) {
                    mx = max(mx, freq[k]);
                    mn = min(mn, freq[k]);
                }
            }

            // Add the beauty of the current substring to the answer
            ans += (mx - mn);
        }
    }

    return ans;
}
};