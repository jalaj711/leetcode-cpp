#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        vector<bool> used (n, false);
        if (n % groupSize) return false;
        sort(hand.begin(), hand.end());
        int currSize = 0;
        for(int i=0;i<n;i++) {
            if (!used[i]) {
                used[i] = true;
                currSize = 1;
                for (int j=i+1;j<n&&currSize<groupSize;j++) {
                    if (!used[j] && hand[i] == hand[j] - currSize) {
                        used[j] = true;
                        currSize++;
                    }
                }
                if (currSize != groupSize) return false;
            }
        }
        return true;
    }
};