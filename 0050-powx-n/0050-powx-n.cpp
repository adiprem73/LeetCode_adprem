class Solution {
public:
    double myPow(double x, int n)
{

    if(x==1.0){
        return x;
    }
    long long N=n;
    if(N<0){
        x=1/x;
        N=-1*N;
    }

    

    double result=1.0;
    while(N>0){
        if(N%2!=0){
            result*=x;
        }

        x*=x;
        N/=2;
    }
    return result;
}
};