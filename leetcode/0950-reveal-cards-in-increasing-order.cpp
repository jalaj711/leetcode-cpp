#include<vector>
#include <queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck) {
        vector<int> result(deck.size(), 0);
        queue<int> q;
        sort(deck.begin(), deck.end());
        for (int i = 0; i < deck.size(); i++) {
            q.push(i);
        }
        int ptr = 0;
        while (!q.empty()) {
            result[q.front()] = deck[ptr];
            ptr++;
            q.pop();
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> q{17, 13, 11, 2, 3, 5, 7};
    s.deckRevealedIncreasing(q);
}
