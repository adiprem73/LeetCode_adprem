class Solution {
public:
    int gcdOfOddEvenSums(int n)
{
    int sumEven=0, sumOdd=0;
    int mark=0;
    int i=1;
    while(mark<n){
        if(i%2==0){
            sumEven+=i;
            mark++;
        }
        i++;
    }
    mark =0;
    i=1;
    while (mark < n)
    {
        if (i % 2 != 0)
        {
            sumOdd += i;
            mark++;
        }
        i++;
    }
    return __gcd(sumEven, sumOdd);
}
};