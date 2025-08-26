class Solution {
public:
    int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // base cases
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            dp[i][j][0] = 0;
        }
    }

    for (int j = 0; j <= 1; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            dp[n][j][k] = 0;
        }
    }

    for (int ind = n-1; ind >= 0; ind--) //running the loop form n will make prices[n] og out of bounds
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++) //cap msu tbe gretaer than 0
            {
                if (buy)
                {
                    dp[ind][buy][cap] = max(-prices[ind] +dp[ind+1][0][cap], dp[ind+1][1][cap]);
                }

                // if its the time to sell then we will take the max of sell and not sell
                else
                {
                    dp[ind][buy][cap] = max(prices[ind] + dp[ind+1][1][cap-1], dp[ind+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}
};