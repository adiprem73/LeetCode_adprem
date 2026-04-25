class Solution {
public:
    bool validDigit(int n, int x) {
        vector<int> digits;
        int cnt =0;
        while(n>0){
            int d = n%10;
            if(d==x){
                cnt++;
            }
            digits.push_back(d);
            n=n/10;
        }

        if(cnt>0 && digits[digits.size() - 1] != x){
            return true;
        }return false;
    }
};