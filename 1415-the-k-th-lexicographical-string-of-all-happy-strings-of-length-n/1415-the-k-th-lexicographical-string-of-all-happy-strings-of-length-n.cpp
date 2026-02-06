class Solution {
public:
    void func(string curr, int n, int k, vector<string> & ans){
    // base case
    if(curr.length()== n){
        ans.push_back(curr);
        return;
    }

    string s= "abc";
    for (auto ch: s){
        if(curr.length()==0){
            func(curr+ch, n, k, ans);
        }else{
            if(ch!= curr[curr.length()-1]){
                func(curr + ch, n, k, ans);
            }
        }
    }
}

string getHappyString(int n, int k) {
    vector<string> ans;
    func("", n, k, ans);
    sort(ans.begin(), ans.end());
    if(k>ans.size()){
        return "";
    }
    return ans[k-1];
}
};