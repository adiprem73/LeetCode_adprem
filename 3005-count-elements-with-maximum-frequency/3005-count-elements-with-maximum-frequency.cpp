class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        int maxi=INT_MIN;
        for(auto it: mp){
            maxi=max(maxi, it.second);
        }
        int cnt=0;
        // cout<<"maxi : "<<maxi<<endl;
        for(auto it: mp){
            // cout<<it.first<<" "<<it.second<<endl;
            if(it.second== maxi){
                cnt+=it.second;
            }
        }
        return cnt;
    }
};