class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int temp = n;
        int rev = 0;
        int sum =0;
        while(temp>0){
            int d = temp%10;
            rev = rev*10 + d;
            temp=temp/10;
        }
        int s = min(n, rev);
        int e = max(n, rev);
        cout<<"n : "<<n<<endl;
        cout<<s<<" & "<<e<<endl;
        int cnt;
        for(int i=s;i<=e;i++){
             cnt=0;
            for(int j=2;j<i;j++){
                if(i%j==0){
                    cnt++;
                }
            }
            if(cnt == 0 && i!=1){
                cout<<"prime no.: "<<i<<endl;
                sum+=i;
            }
        }
        return sum;
    }
};