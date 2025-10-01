class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt=numBottles;
        int remaining=0;
        while(numBottles>=numExchange){
            int newBottles= numBottles/ numExchange;
            remaining= numBottles% numExchange;
            // cout<<cnt<<endl;
            cnt+=newBottles;
            numBottles= newBottles+ remaining;
        }
        return cnt;
    }
};