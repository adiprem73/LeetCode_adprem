class Solution {
public:
    string reversePrefix(string s, int k) {
        string s1 = s.substr(0,k);
        string s2 = s.substr(k);
        reverse(s1.begin(), s1.end());
        return s1+s2;
    }
};