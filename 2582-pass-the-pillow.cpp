class Solution {
public:
    int passThePillow(int n, int time) {
        n--;
        int dir = (time / n) & 1;
        int pos = (time % n);
        return (dir ? (n - pos) : pos) + 1;
    }
};