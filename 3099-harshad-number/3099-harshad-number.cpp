class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int n = x;
        int sumOfDigits =0;
        while(n>0){
            int d = n%10;
            sumOfDigits += d;
            n= n/10;
        }
        if(x % sumOfDigits == 0)return sumOfDigits;
        return -1;
    }
};