class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // map each letter to its keyboard row
        vector<int> row(26, 0);
        string r1 = "qwertyuiop", r2 = "asdfghjkl", r3 = "zxcvbnm";
        for (char c : r1) row[c - 'a'] = 0;
        for (char c : r2) row[c - 'a'] = 1;
        for (char c : r3) row[c - 'a'] = 2;

        vector<string> res;
        for (auto &w : words) {
            int first = row[tolower(w[0]) - 'a'];
            bool ok = true;
            for (char c : w) {
                if (row[tolower(c) - 'a'] != first) {
                    ok = false;
                    break;
                }
            }
            if (ok) res.push_back(w);
        }
        return res;
    }
};