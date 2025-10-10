class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k){
    int n = energy.size();
    vector<int> dp(n);
    for(int i=0;i<k;i++){
        dp[n-1-i]= energy[n-1-i];
    }

    for(int i=n-k-1;i>=0;i--){
        dp[i]= dp[i+k]+ energy[i];
    }
    // vprint(dp);
    return *max_element(dp.begin(), dp.end());
}
};