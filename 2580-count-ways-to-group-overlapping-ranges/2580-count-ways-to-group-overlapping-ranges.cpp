class Solution {
public:

    long long power(int x, int n)
{
    if (n == 0)
    {
        return 1LL;
    }
    long long ans;
    if (n % 2 == 0)
    {
        ans = (power((1LL* x * x) % MOD, n / 2)) % MOD;
    }
    else
    {
        ans = (x * (power(x, n - 1)) % MOD) % MOD;
    }
    return ans;
}

    const long long MOD = 1e9+7;
    int countWays(vector<vector<int>>& ranges) {
    int n = ranges.size();
    vector<vector<int>> merged;
    sort(ranges.begin(), ranges.end());
    merged.push_back(ranges[0]);
    for(int i=1;i<n;i++){
        if(ranges[i][0]<=merged.back()[1]){
            merged.back()[1] = max(merged.back()[1], ranges[i][1]);
        }else{
            merged.push_back(ranges[i]);
        }
    }   
    // for(auto it: merged){
    //     vprint(it);
    // }
    int x = merged.size(); 
    int ans =0;

    ans = power(2,x);
    return ans;
}
};