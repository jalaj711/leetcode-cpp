#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;
        int p = 0;
        int q = 1;
        int max_profit = 0;
        while (q < prices.size())
        {
            if (prices[p] > prices[q])
                p = q;
            else
                max_profit = max(max_profit, prices[q] - prices[p]);
            q++;
        }
        return max_profit;
    }
};

int main()
{
    vector<int> q = {7,6,1,5,9,10,7};
    Solution s;
    s.maxProfit(q);
    return 0;
}
