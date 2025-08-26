class Solution {
public:
    
int maxProfit(vector<int> & prices){
    int n = prices.size();
    long aheadBuy, aheadNotBuy, curBuy, curNotBuy;
    aheadBuy=aheadNotBuy=0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
        
            curBuy = max((-prices[ind] + aheadNotBuy), aheadBuy);
            curNotBuy = max((prices[ind] + aheadBuy), (aheadNotBuy));
        
        }
        aheadBuy=curBuy;
        aheadNotBuy=curNotBuy;
    }
    return aheadBuy;
}
};