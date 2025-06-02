class Solution {
public:
    bool wordPattern(string pattern, string s) {
    map<char, string> mp;
    map<string, char> rev_mp;
    vector<string> sen;
    string word = "";
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == ' ') {
            sen.push_back(word);
            word = "";
        } else {
            word += ch;
        }
    }
    sen.push_back(word);

    if (pattern.size() != sen.size()) return false;

    for (int i = 0; i < pattern.size(); i++) {
        char p = pattern[i];
        string w = sen[i];
        if (mp.count(p)) {
            if (mp[p] != w) return false;
        } else {
            if (rev_mp.count(w)) return false;
            mp[p] = w;
            rev_mp[w] = p;
        }
    }
    return true;
}
};