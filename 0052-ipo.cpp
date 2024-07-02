#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>> pq;
        int n = profits.size();
        for (int i = 0;i < n;i++) {
            pq.push({profits[i], capital[i]});
        }
        vector<pair<int, int>> rejected;
        while(k&&!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if (top.second <= w) {
                w += top.first;
                k--;
                for (int j=0;j<rejected.size();j++) {
                    if (rejected[j].second <= w) {
                        pq.push(rejected[j]);
                        rejected.erase(rejected.begin()+j);
                        break;
                    }
                }
            } else {
                rejected.push_back(top);
            }
        }
        return w;
    }
};