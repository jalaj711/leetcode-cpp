#include<queue>
#include<vector>
using namespace std;

//class Solution {
//public:
//    int islandPerimeter(vector<vector<int>>& grid) {
//        int m = grid.size();
//        int n = grid[0].size();
//        queue<pair<int, int>> q;
//        for(int i=0;i<m&&q.empty();i++) {
//            for (int j=0;j<n;j++) {
//                if(grid[i][j]) {
//                    q.push({i, j});
//                    grid[i][j] = 2;
//                    break;
//                }
//            }
//        }
//        int perimeter = 0;
//        int sz, nx, ny;
//        pair<int, int> fr;
//        pair<int, int> dirs[4] = {{1,0}, {-1, 0}, {0,1}, {0, -1}};
//        while(!q.empty()) {
//            sz = q.size();
//            while(sz--) {
//                fr = q.front();
//                q.pop();
//                for (auto dir: dirs) {
//                    nx = fr.first+dir.first;
//                    ny = fr.second+dir.second;
//                    if (nx < 0 || nx > m-1 || ny < 0 || ny > n-1 || grid[nx][ny] == 0) {
//                        perimeter++;
//                    } else if (grid[nx][ny] == 1) {
//                        grid[nx][ny] = 2;
//                        q.push({nx, ny});
//                    }
//                }
//            }
//        }
//        return perimeter;
//    }
//};
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int perimeter = 0;
        int nx, ny;
        pair<int, int> dirs[4] = {{1,0}, {-1, 0}, {0,1}, {0, -1}};
        for(int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 2;
                    for (auto dir: dirs) {
                        nx = i+dir.first;
                        ny = j+dir.second;
                        if (nx < 0 || nx > m-1 || ny < 0 || ny > n-1 || grid[nx][ny] == 0) {
                            perimeter++;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};

int main(){
    vector<vector<int>> grid {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    Solution s;
    s.islandPerimeter(grid);
}