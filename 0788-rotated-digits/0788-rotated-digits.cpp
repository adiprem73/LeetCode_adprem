class Solution {
public:
    int rotatedDigits(int n)
{ 
    unordered_set<int> check={0,1,2,5,6,8,9};  
    int cnt =0;
    for(int i=1;i<=n;i++){
        int num =i;
        bool flag = true;
        int rev1=0,rev2=0;
        while(num>0){
            int d = num%10;
            rev1= rev1*10 + d;
            num=num/10;
            if(check.count(d)<=0){
                flag = false;
                break;
            }

            if(d==0 || d==1 || d==8){
                rev2 = rev2*10 + d;
            }
            else if(d==2){
                rev2 = rev2*10 + 5;
            }
            else if(d==5){
                rev2 = rev2*10 + 2;
            }
            else if (d == 6)
            {
                rev2 = rev2 * 10 + 9;
            }
            else if (d == 9)
            {
                rev2 = rev2 * 10 + 6;
            }
        }
        if(flag == true){
            if(rev1 != rev2){
                // cout<<rev2<<endl;
                cnt++;
            }
        }
    }
    return cnt;
}
};