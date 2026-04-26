class Solution(object):
    def maxProfit(self, prices):
        l=0
        r=1
        max_profit=0
        while(r<len(prices)):
            if(prices[l]<prices[r]):
                max_profit=max(max_profit, prices[r]-prices[l])
            else:
                l=r
            r+=1
            
        return max_profit
        