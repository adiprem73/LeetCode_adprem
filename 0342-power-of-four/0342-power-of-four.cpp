class Solution {
public:
    bool isPowerOfFour(int n) {
    if(n<=0 || n==2 || n==8 ||n==32||n==128||n==512){
        return false;
    }return 1073741824%n==0;
}
};