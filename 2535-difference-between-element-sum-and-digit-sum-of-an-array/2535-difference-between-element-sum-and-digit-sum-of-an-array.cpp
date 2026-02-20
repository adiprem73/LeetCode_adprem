class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=0, digitSum =0;
        for(auto it: nums){
            sum+=it;
            int n = it;
            while(n>0){
                int d = n% 10;
                digitSum += d;
                n=n/10;
            }
        }
        return abs(sum - digitSum);
    }
};