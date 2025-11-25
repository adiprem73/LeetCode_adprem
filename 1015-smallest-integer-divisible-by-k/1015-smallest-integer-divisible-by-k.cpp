class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int x=0;
        unordered_set<int> seen;
        int len=0;
        while(true){
            x=(x*10 + 1)%k;

            len++;
            if(x==0){
                return len;
            }

            if(seen.count(x)){
                return -1; //this will only repeat the ahead iterations
            }
            seen.insert(x);
        }
        return -1;
    }
};