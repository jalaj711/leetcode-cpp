#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
  int maxCandies(
      vector<int> &status,
      vector<int> &candies,
      vector<vector<int>> &keys,
      vector<vector<int>> &containedBoxes,
      vector<int> &initialBoxes
  ) {
    int n = status.size();
    int total = 0;
    vector<bool> processed(n, false);
    vector<bool> boxes(n, false);

    queue<int> q;

    for (const auto &i: initialBoxes) {
      boxes[i] = true;
      if (boxes[i] && status[i]) {
        processed[i] = true;
        q.push(i);
      }
    }

    while (!q.empty()) {
      int fr = q.front();
      q.pop();

      total += candies[fr];
      for (const auto &i: keys[fr]) {
        status[i] = true;
        if (status[i] && boxes[i] && !processed[i]) {
          processed[i] = true;
          q.push(i);
        }
      }

      for (const auto &i: containedBoxes[fr]) {
        boxes[i] = true;
        if (status[i] && boxes[i] && !processed[i]) {
          processed[i] = true;
          q.push(i);
        }
      }
    }

    return total;
  }
};