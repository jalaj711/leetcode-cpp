#include<vector>
using namespace std;
class Solution {
public:
  int recur(vector<int> &days, vector<int> &costs, int idx, int day,  vector<int> &memo) {
    if (idx >= days.size() || day > days[days.size()-1]) return -1;
    while (days[idx] < day && idx < days.size()) idx++;
    day = days[idx];
    if (memo[day] > -1) return memo[day];

    int one = recur(days, costs, idx, day+1, memo);
    if (one > -1) one += costs[0];
    else one = costs[0];

    int three = recur(days, costs, idx, day+7, memo);
    if (three > -1) three += costs[1];
    else three = costs[1];

    int seven = recur(days, costs, idx, day+30, memo);
    if (seven > -1) seven += costs[2];
    else seven = costs[2];

    return memo[day] = min(one, min(three, seven));

  }
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> memo (366, -1);
    return recur(days, costs, 0, 1, memo);
  }
};