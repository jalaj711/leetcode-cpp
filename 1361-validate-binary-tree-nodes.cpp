#include<vector>

using namespace std;

class Solution {
public:
    vector<int> par;

    int find(int u) {
        if (u == par[u]) return u;
        return par[u] = find(par[u]);
    }

    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild) {
        par.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
        int p_i, p_lc;
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                p_i = find(i);
                p_lc = find(leftChild[i]);
                if (p_i == p_lc || p_lc != leftChild[i]) return false;
                par[p_lc] = p_i;
            }
            if (rightChild[i] != -1) {
                p_i = find(i);
                p_lc = find(rightChild[i]);
                if (p_i == p_lc || p_lc != rightChild[i]) return false;
                par[p_lc] = p_i;
            }

        }
        int count = 0;
        for (int i = 0; i < n; i++)
            if (par[i] == i) {
                if (count) return false;
                else count++;
            }

        return count == 1;
    }
};