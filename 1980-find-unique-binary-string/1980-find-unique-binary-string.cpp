class Solution {
public:
    void func(int n, string &curr, vector<string> & ans){
    // base case
    if(curr.length()== n){
        ans.push_back(curr);
        return;
    }

    curr.push_back('0');
    func(n, curr, ans);
    curr.pop_back();

    curr.push_back('1');
    func(n, curr, ans);
    curr.pop_back();
}


vector<string> makeAllBinaryCombinations(int n){
    vector<string> ans;
    string curr;
    func(n, curr, ans);
    return ans;
}

string findDifferentBinaryString(vector<string>& nums) {
    if(nums.size()==0){
        return "";
    }

    int n= nums[0].length();
    vector<string> ans = makeAllBinaryCombinations(n);
    sort(nums.begin(), nums.end());
    int i=0;
    while(i<nums.size()){
        if(nums[i]!= ans[i]){
            return ans[i];
        }
        i++;
    }
    return ans[i];

}
};