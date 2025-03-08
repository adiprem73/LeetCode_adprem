class Solution {
public:
    int reverseNum(int num){
    int rev=0;
    while(num>0){
        int d=num%10;
        cout<<d<<endl;
        rev=rev*10+d;
        num=num/10;
    }
    return rev;
}

bool isSameAfterReversals(int num){
    int rev1=reverseNum(num);
    int rev2=reverseNum(rev1);
    bool flag=rev2==num;
    return flag;
}
};