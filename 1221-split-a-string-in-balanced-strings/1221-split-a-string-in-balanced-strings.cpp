class Solution {
public:
    int balancedStringSplit(string s) {
        int cR=0, cL=0;
        int cnt=0;
        for(char ch: s){
            if(ch=='L'){
                cL++;
            }else{
                cR++;
            }

            if(cL==cR){
                cnt++;
                cL=0;
                cR=0;
            }
        }
        return cnt;
    }
};