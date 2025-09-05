class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
    for(int k=1;k<=60;k++){
        long long n= (long long)num1 - 1LL*k*num2;
        if(n<0)continue;

        if(__builtin_popcountll(n)<= k && k<=n) {
            return k;
        }
    }
    return -1;
}
};