class Solution {
public:
    void func(vector<int>& curr, int &n, int &k, vector<vector<int>> & ans, int start){
    if(curr.size()==k){
        ans.push_back(curr);
        return;
    }

    for(int i=start;i<=n;i++){
        curr.push_back(i);
        func(curr, n, k, ans, i+1);
        curr.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> curr;
    int start=1;
    func(curr, n, k, ans, start);
    return ans;
}
};