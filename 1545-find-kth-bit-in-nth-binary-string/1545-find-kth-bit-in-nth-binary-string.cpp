class Solution {
public:
    char findKthBit(int n, int k)
{
    if(n==1){
        return '0';
    }
    int len = (1 << n) - 1;

    int half = len/2;
    if(k-1<half){
        return findKthBit(n-1, k);
    }
    if(k-1== half){
        return '1';
    }
    else{
        if(findKthBit(n-1, len-k+1)=='0')return '1';
        else return '0';
    }
}
};