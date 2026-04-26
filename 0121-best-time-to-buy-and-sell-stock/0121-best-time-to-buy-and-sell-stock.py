class Solution(object):
    def maxProfit(self, prices):
        n = len(prices)
        max_profit = 0

        for i in range(n):  # buy day
            for j in range(i + 1, n):  # sell day (must be after buy)
                profit = prices[j] - prices[i]
                max_profit = max(max_profit, profit)

        return max_profit