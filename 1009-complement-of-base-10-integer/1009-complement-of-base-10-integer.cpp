class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        string bin = "";
        while(n>0){
            bin = to_string(n%2) + bin;
            n=n/2;
        }
        int ans=0;
        int  x =0;
        int num = bin.length();
        for(int i = num-1;i>=0;i--){
            ans += pow(2, x) * (1-(bin[i] - '0'));
            x++;
        }   
        return ans;
    }
};