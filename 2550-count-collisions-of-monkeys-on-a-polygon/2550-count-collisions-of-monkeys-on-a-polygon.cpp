class Solution {

    const long long MOD = 1e9+7;
public:
    int func(int a, int n){
    if(n==0){
        return 1;
    }

    if(n%2==0){
        return func((a%MOD*a%MOD)%MOD, n/2)%MOD;
    }else{
        return (a%MOD*func(a, n-1)%MOD)%MOD;
    }
}

int monkeyMove(int n) {
    return (func(2, n)%MOD - 2 + MOD)%MOD;
}
};