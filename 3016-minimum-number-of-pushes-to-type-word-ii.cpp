#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int keysUsed = 0, pushes = 0;
        vector<int> freq(26, 0);
        for (char ch: word) freq[ch - 'a']++;
        sort(freq.begin(), freq.end(), greater<int>());
        for (int f: freq) pushes += (keysUsed++ / 8 + 1) * f;
        return pushes;
    }
};