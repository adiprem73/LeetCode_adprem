class Solution {
public:
    void makeStrings(int ind, string st, vector<string> & ans, int & n){
    // base case
    if(ind == n){
        ans.push_back(st);
        return;
    }

    // adding '1' is alway allowed
    makeStrings(ind+1, st+"1", ans, n);

    if(st.empty() || st.back() == '1'){
        makeStrings(ind+1, st+'0' , ans, n);
    }
}

vector<string> validStrings(int n){
    vector<string> ans;
    makeStrings(0, "", ans, n);
    return ans;
}
};