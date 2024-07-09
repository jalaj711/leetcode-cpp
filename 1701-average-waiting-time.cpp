#include "vector"

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>> &customers) {
        double totalWaitTime = 0.0;
        int chefAvailableFrom = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (chefAvailableFrom < customers[i][0]) {
                totalWaitTime += customers[i][1];
                chefAvailableFrom = customers[i][1] + customers[i][0];
            } else {
                totalWaitTime += (chefAvailableFrom - customers[i][0]) + customers[i][1];
                chefAvailableFrom += customers[i][1];
            }
        }
        return totalWaitTime / customers.size();
    }
};