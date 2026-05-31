class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> parking(101,0);
        for(auto it: nums){
            for(int i=it[0];i<=it[1];i++){
                if(parking[i]==0){
                    parking[i]=1;
                }                
            }
        }
        int ans=0;
        for(auto it: parking){
            if(it==1){
                ans++;
            }
        }
        return ans;
    }
};