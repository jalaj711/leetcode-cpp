class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 0) return false;

        int one = 0;
        int zero = 0;

        while (n) {
            n & 1 ? one++ : zero++;
            n = n >> 1;
        }
        if (one == 1 && zero % 2 == 0) return true;
        return false;
    }
};