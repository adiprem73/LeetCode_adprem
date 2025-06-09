class Solution {
public:
    double myPow(double x, int n){
    if(n==0 || x==1){
        return 1;
    }

    long long temp=n;
    temp=abs(temp);

    double ans=1;
    while(temp>0){
        if(temp%2==1){
            ans*=x;
        }
        x*=x;
        temp/=2;
    }

    return (n<0)?1/ans:ans;
}
};