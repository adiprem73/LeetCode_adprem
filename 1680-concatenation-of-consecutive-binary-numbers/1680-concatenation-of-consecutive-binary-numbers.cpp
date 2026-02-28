class Solution {
public:
    int convert2Binary(int n){
    int cnt=0;
    while(n>0){
        n= n/2;
        cnt++;
    }
    return cnt;
}

int concatenatedBinary(int n) {
    long long sum=1;
    const int MOD = 1e9 + 7;
    for(int i=2;i<=n;i++){
        // cout<<convert2Binary(i)<<endl;
        // cout<<sum<<endl;
        sum= ((sum << convert2Binary(i)) + i) % MOD;
    }
    return sum;
}
};