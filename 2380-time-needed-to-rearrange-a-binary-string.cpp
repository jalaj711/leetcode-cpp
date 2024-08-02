#include<string>
class Solution {
public:
    int secondsToRemoveOccurrences(std::string s) {
        int time = 0;
        int n = s.size();
        bool flag = true;
        while(flag) {
            flag = false;
            for (int i=0;i<n-1;i++) {
                if (s[i] == '0' && s[i+1] == '1') {
                    flag = true;
                    s[i] = '1';
                    s[i+1] = '0';
                    i++;
                }
            }
            time++;
        }
        return time-1;
    }
};