#include <string>
#include <queue>
using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int validr = 0, validd = 0, removedr = 0, removedd = 0;
        queue<bool> q;
        for (auto ch : senate)
        {
            ch == 'R' ? validr++ : validd++;
            q.push(ch == 'R');
        }

        bool e;
        while (!q.empty() && validd != 0 && validr != 0)
        {
            e = q.front();
            q.pop();
            if (e && removedr)
            {
                removedr--;
                validr--;
                continue;
            }
            if (!e && removedd)
            {
                removedd--;
                validd--;
                continue;
            }
            if (e && validr)
                q.push(e), removedd++;
            else if (!e && validd)
                q.push(e), removedr++;
        }

        if (validd > validr)
            return "Dire";
        return "Radiant";
    }
};
