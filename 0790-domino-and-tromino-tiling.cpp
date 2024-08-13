#include <vector>

using namespace std;

class Solution {
public:
    int inf = 1e9 + 7;

    int numTilings(int n) {
        if (n==1) return 1;
        vector<int> plus_two {1, 0};
        vector<int> plus_one {2, 1};
        vector<int> curr {0, 0};
        int domino, tromino;
        for (int i = n - 2; i > 0; i--) {
            domino = (plus_one[0] + plus_two[0]) % inf;
            tromino = (2 * plus_one[1]) % inf;
            curr[0] = (domino + tromino) % inf;

            domino = plus_one[1];
            tromino = plus_two[0];
            curr[1] = (domino + tromino) % inf;

            plus_two = plus_one;
            plus_one = curr;
        }
        return plus_one[0];
    }
};
