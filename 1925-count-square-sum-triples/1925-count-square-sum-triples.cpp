class Solution {
public:
    int countTriples(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int x= i*i + j*j;
                int rootX= sqrt(x);
                if(rootX*rootX==x || (rootX+1)*(rootX+1)==x){
                    if(rootX<=n){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};