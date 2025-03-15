class Solution {
public:
    int maxProfit(vector<int>& prices){
    int minIndex=0;
    int maxprofit=0;
    int n=prices.size();
    for(int i=1;i<n;i++){
        if(prices[i]<prices[minIndex]){
            minIndex=i;
        }
        if((prices[i]-prices[minIndex])>maxprofit){
            maxprofit=prices[i]-prices[minIndex];
        }
    }
    return maxprofit;
}
};