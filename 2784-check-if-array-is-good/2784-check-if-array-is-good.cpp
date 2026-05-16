class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        for(auto it: mp){
            cout<<it.first<<" : "<<it.second<<endl;
        }
        bool flag = false;
        if(mp[n-1]!=2){
            return false;
        }
        for(int i=1;i<n-1;i++){
            if(mp.count(i)>0){
                if(mp[i]!=1){
                    return false;
                }
            }else{
                return false;
            }
        }
        return true;
    }
};