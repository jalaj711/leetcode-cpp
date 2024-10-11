#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
  int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int n = times.size();

    // status of each chair: false = free, true = used
    vector<bool> status (n, false);
    // pointer to smallest available chair
    int ptr = 0;

    // min heap of when to free each chair
    // last 14 bits = chair number
    // next 17 bits = time of operation
    priority_queue<int, vector<int>, greater<int>> free_at;
    int target = times[targetFriend][0];

    sort(times.begin(), times.end());

    for (int i=0;i<n;i++) {
      int arr = times[i][0];
      int dep = times[i][1];

      while(!free_at.empty() && (free_at.top() >> 14) <= arr){
        int chair = free_at.top() & ((1<<14)-1);
        status[chair] = false;
        if (chair < ptr) ptr = chair;
        free_at.pop();
      }

      if (arr == target) break;
      status[ptr] = true;
      free_at.push((dep << 14) | ptr);
      while(status[ptr]) ptr++;
    }

    return ptr;
  }
};