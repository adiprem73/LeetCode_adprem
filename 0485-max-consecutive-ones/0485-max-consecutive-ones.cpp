class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int l=0;l<n;l++){
            
            int cnt=0;
            while(l<n && nums[l]==1){
                // cout<<l<<endl;
                l++;
                cnt++;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};