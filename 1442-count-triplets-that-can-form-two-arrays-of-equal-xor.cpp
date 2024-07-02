#include<vector>
using namespace std;


class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        int n = arr.size();
        int x;
        for (int i=0;i<n-1;i++) {
            x = arr[i];
            for (int j=i+1;j<n;j++) {
                x ^= arr[j];
                if (x == 0) {
                    count+=j-i;
                }
            }
        }
        return count;
    }
};