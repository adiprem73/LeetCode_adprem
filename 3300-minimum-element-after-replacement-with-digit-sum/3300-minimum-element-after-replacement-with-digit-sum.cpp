class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn =INT_MAX;
        for(auto it: nums){
            int sum =0;
            while(it>0){
                int d = it%10;
                it=it/10;
                sum+=d;
            }
            mn = min(mn, sum);
        }
        return mn;
    }
};