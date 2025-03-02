class Solution {
public:
    bool isPalindrome(int x) {
    long num=x;
    long i=x;
    long rev=0;
    while(i>0){
        long d=i%10;
        rev=rev*10+d;
        i=i/10;
    }
    if(num==rev){
        return true;
    }
    else{
        return false;
    }
    }
};