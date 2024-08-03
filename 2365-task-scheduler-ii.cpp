#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long answer = 0;
        unordered_map<int, long long> mp;
        for (int i=0;i<tasks.size();i++) {
            if (mp.find(tasks[i]) != mp.end()) {
                if (answer < mp[tasks[i]]) {
                    answer += (mp[tasks[i]] - answer);
                }
                answer++;
                mp[tasks[i]] = answer + space;
            } else {
                answer++;
                mp[tasks[i]] = answer + space;
            }
        }
        return answer;
    }
};