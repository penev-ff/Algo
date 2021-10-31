/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *  Time: O(n)
 *  Space: O(1)
 * 
*/

#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;

    if (prices.size() > 0)
    {
        int minPrice = prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }

            if (prices[i] - minPrice > maxProfit)
            {
                maxProfit = prices[i] - minPrice;
            }
        }
    }

    return maxProfit;
}

int main()
{
    return 0;
}