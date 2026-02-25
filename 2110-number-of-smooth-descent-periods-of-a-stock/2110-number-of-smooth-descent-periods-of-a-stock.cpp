class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
    long long ans =0;
    int n = prices.size();
    int left =0;
    vector<vector<int>> periods;
    vector<int> curr;
    curr.push_back(prices[0]);
    for(int right =1; right<n ;right++){
        if(prices[right-1] - prices[right] != 1){
            left = right;
            periods.push_back(curr);
            curr.clear();
        }
        curr.push_back(prices[right]);
    }    
    periods.push_back(curr); 
    for(auto it: periods){
        int x = it.size();
        // vprint(it);
        // cout<<x<<endl;
        ans += 1LL *(x)*(x+1)/2;
    }   
    return ans;
}
};