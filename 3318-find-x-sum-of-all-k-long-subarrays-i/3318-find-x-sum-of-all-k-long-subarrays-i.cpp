class Solution {
public:
    
int findSum(vector<int>& nums, int l, int r, int x){
    unordered_map<int,int> mp;

    for(int i=l;i<r;i++)
        mp[nums[i]]++;

    vector<int> vals;
    for(auto &p: mp)
        vals.push_back(p.first);

    sort(vals.begin(), vals.end(), [&](int a,int b){
        if(mp[a]!=mp[b]) return mp[a]>mp[b];
        return a>b;
    });

    int ans=0;
    for(int i=0;i<min(x,(int)vals.size());i++)
        ans += vals[i] * mp[vals[i]];   // ⭐ FIX

    return ans;
}

vector<int> findXSum(vector<int>& nums, int k, int x){
    int n = nums.size();
    vector<int> ans;
    for(int i=0;i<n-k+1;i++){
        ans.push_back(findSum(nums, i, i+k, x));
    }
    return ans;
}
};