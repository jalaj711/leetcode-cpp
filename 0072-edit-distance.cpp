#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();
        vector<int> curr(s2+1, 0);

        for (int i=0;i<s2;i++) {
            curr[i] = s2-i;
        }
        int prev, temp;
        for (int idx1=s1-1;idx1>=0;idx1--) {
            prev = curr[s2];
            curr[s2] = s1-idx1;
            for (int idx2=s2-1;idx2>=0;idx2--) {
                temp = prev;
                if (word1[idx1] != word2[idx2]) temp++;
                prev = curr[idx2];
                curr[idx2] = min(temp, min(1 + curr[idx2], 1 + curr[idx2+1]));
            }
        }

        return curr[0];
    }
};

int main() {
    Solution s;
    s.minDistance("horse", "ros");
}