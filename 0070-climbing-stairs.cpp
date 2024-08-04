class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int plus_one = 2;
        int plus_two = 1;
        int ans = 0;
        for (int i = n - 3; i >= 0; i--) {
            ans = plus_one + plus_two;
            plus_two = plus_one;
            plus_one = ans;
        }
        return ans;
    }
};