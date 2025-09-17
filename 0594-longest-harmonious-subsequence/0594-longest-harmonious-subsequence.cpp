class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        vector<int> arr;
        for(auto it: mp){
            arr.push_back(it.first);
        }
        sort(arr.begin(), arr.end());
        int maxi=0;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==1){
                maxi=max(maxi, mp[arr[i]]+mp[arr[i+1]]);
            }
        }
        
        return maxi;
    }
};