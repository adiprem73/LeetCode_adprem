class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        for(int i: nums){
            if(i==1){
                cnt+=1;
            }
            else if(i==2){
                cnt+=1;
            }else if(i%3!=0){
                cnt+=1;
            }
        }return cnt;
    }
};