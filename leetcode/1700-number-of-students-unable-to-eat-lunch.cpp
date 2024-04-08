#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int z=0;
        int o=0;
        for (auto it: students) {
            q.push(it);
            if (it) o++;
            else z++;
        }
        int fr;
        int snd = 0;
        while (!q.empty()&&snd<sandwiches.size()) {
            fr = q.front();
            q.pop();
            if (sandwiches[snd] == fr) {
                if (fr) o--;
                else z--;
                snd++;
            } else if ((sandwiches[snd]==1&&o==0)||(sandwiches[snd]==0&&z==0)) {
                return q.size()+1;
            } else {
                q.push(fr);
            }
        }
        return q.size();
    }
};