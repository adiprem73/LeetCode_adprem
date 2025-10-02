class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int cnt= numBottles;
        int fullBottles=0;
        int emptyBottles= numBottles;
        while(emptyBottles>=numExchange){
            emptyBottles-= numExchange;
            emptyBottles++;
            numExchange++;
            cnt++;
        }
        return cnt;
    }
};