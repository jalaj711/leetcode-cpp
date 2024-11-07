#include<vector>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
  int get_dist(const string &a, const string &b) {
    int d = 0;
    for(int i=0;i<8;i++) d += (a[i] != b[i]);
    return d;
  }
  int minMutation(const string &start, const string &end, vector<string>& bank) {
    int n = bank.size();
    int startIdx = -1, endIdx = -1;
    for(int i=0;i<n;i++) {
      if (bank[i] == start) startIdx = i;
      if (bank[i] == end) endIdx = i;
    }

    if (startIdx == -1) {
      bank.push_back(start);
      startIdx = n++;
    }

    vector<int> dis (n, 1e9);
    priority_queue<
    pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({0, startIdx});
    dis[startIdx] = 0;

    while(!pq.empty()) {
      int gene = pq.top().second;
      int d = pq.top().first;
      pq.pop();

      for(int i=0;i<n;i++) {
        if (i == gene) continue;
        int diff = get_dist(bank[gene], bank[i]);
        if (diff > 1) continue;
        if (i == endIdx) return d+1;
        if (d + 1 < dis[i]) {
          dis[i] = d+1;
          pq.push({d+1, i});
        }
      }
    }

    return -1;
  }
};