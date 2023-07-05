#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;

        int p = 0, q = 1, profit = 0;
        while (q < prices.size())
        {
            if (prices[p] > prices[q])
                p = q;
            else if (q == prices.size() - 1)
                profit += prices[q] - prices[p];
            else if (prices[q + 1] < prices[q])
            {
                profit += prices[q] - prices[p];
                p = q;
            }
            q++;
        }
        return profit;
    }
};

int main()
{
    vector<int> q = {7, 6, 1, 5, 9, 4, 7};
    Solution s;
    s.maxProfit(q);
    return 0;
}
