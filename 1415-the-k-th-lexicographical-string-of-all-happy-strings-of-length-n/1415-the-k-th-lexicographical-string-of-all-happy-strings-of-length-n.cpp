class Solution {
public:
    void func(string curr, int n, int &k, string &ans) {
    if (k == 0) return;

    if (curr.length() == n) {
        k--;
        if (k == 0) ans = curr;
        return;
    }

    string s = "abc";
    for (char ch : s) {
        if (curr.empty() || ch != curr.back()) {
            func(curr + ch, n, k, ans);
        }
    }
}

string getHappyString(int n, int k) {
    string ans = "";
    func("", n, k, ans);
    return ans;
}


};