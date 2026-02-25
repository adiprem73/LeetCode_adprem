class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int cntW=0;
        int cntB=0;
        for(int i=0;i<k;i++){
            if(blocks[i] == 'W')cntW++;
            else cntB++;
        }
        int ans = cntW;
        for(int i=1;i<n-k+1;i++){
            if(blocks[i+k-1] == 'B'){
                cntB++;
            }
            if(blocks[i-1] == 'B'){
                cntB--;
            }
            if(blocks[i+k-1] == 'W'){
                cntW++;
            }
            if(blocks[i-1] == 'W'){
                cntW--;
            }
            ans = min(ans, cntW);
        }
        return ans;
    }
};