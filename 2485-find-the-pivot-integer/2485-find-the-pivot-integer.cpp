class Solution {
public:
    int pivotInteger(int n) {
        int totalSum =0;
        for(int i=1;i<=n;i++){
            totalSum += i;
        }
        int sum2 =0;
        for(int i=n;i>=1;i--){
            totalSum -= i;
            sum2 += i;
            int sum1= totalSum + i;
            if(sum1 == sum2)return i;
        }
        return -1;
    }
};