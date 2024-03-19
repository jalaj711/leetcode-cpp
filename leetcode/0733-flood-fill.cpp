#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int start = image[sr][sc];

        if (start == color) return image;

        image[sr][sc] = color;

        queue<pair<int, int>> q;
        q.push({sr,sc});
        int z;
        pair<int, int> fr;
        while (!q.empty()) {
            z = q.size();
            while(z--) {
                fr = q.front();
                q.pop();
                if (fr.first > 0 && image[fr.first-1][fr.second] == start) {
                    image[fr.first-1][fr.second] = color;
                    q.push({fr.first-1, fr.second});
                }
                if (fr.first <m-1 && image[fr.first+1][fr.second] == start) {
                    image[fr.first+1][fr.second] = color;
                    q.push({fr.first+1, fr.second});
                }
                if (fr.second > 0 && image[fr.first][fr.second-1] == start) {
                    image[fr.first][fr.second-1] = color;
                    q.push({fr.first, fr.second-1});
                }
                if (fr.second <n-1 && image[fr.first][fr.second+1] == start) {
                    image[fr.first][fr.second+1] = color;
                    q.push({fr.first, fr.second+1});
                }
            }
        }
        return image;
    }
};

int main () {
    vector<vector<int>> q{{ 1,1,1},{ 1,1,0},{ 1,0,1}};
    Solution s;
    s.floodFill(q, 1, 1, 2);
}
