#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  // binary search for the largest element with price
  // less than the given price. returns -1 if not possible.
  int findItem(int price, vector<vector<int>> &items) {
    int l = 0,
        r = items.size() - 1,
        m,
        a = -1;
    while(l <= r) {
      m = (l+r)/2;
      if (items[m][0] <= price) {
        a = m;
        l = m+1;
      } else{
        r = m-1;
      }
    }
    return a;
  }
  vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    // sort the items on price
    sort(items.begin(), items.end(), [](vector<int> &a, vector<int>&b) {
      if (a[0] != b[0]) return a[0] < b[0];
      return a[1] < b[1];
    });

    // what this loops essentially does is to make the beauty
    // of each item increasing with the price. Consider if the
    // input has the items (2,5), (3,4). When sorted by price
    // it is impossible to search for max beauty in an efficient
    // manner. Since the question says for _any_ price less than
    // queries[i]. If we have, say 4 units, then we will still go
    // for the item with price 2 not the one with price 3.
    //
    // So this loops updates items array so that for each price
    // the beauty is the max for any price less than the current
    // one. this allows for using binary search on all queries.
    int maxBeauty = items[0][1];
    for(auto &item: items) {
      item[1] = max(maxBeauty, item[1]);
      maxBeauty = item[1];
    }

    int n = queries.size();
    vector<int> ans(n);

    for (int i=0;i<n;i++) {
      int idx = findItem(queries[i], items);
      if (idx == -1) ans[i] = 0;
      else ans[i] = items[idx][1];
    }

    return ans;
  }
};