class Solution {
public:
    int reverse(int x) {
        long rev =0;
        bool flag = false;
        if(x<0){
            flag = true;
            x*=-1*1LL;
        }
        while(x>0){
            int d = x%10;
            rev = rev*10*1LL +d;
            x=x/10;
        }
        if(rev>2147483647){
            return 0;
        }
        if(flag){
            return -1*rev;
        }
        return rev;
    }
};