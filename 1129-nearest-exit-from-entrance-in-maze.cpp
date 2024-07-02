#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> bfs;

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int m = maze.size();
        int n = maze[0].size();

        queue<bfs> q;
        q.push({entrance[0], entrance[1]});

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[entrance[0]][entrance[1]] = true;

        int level = 0;
        int min_distance = 10001;
        bfs curr;

        while (!q.empty())
        {
            int qn = q.size();
            while (qn--)
            {
                curr = q.front();
                if ((curr.first == 0 || curr.second == 0 || curr.first == m - 1 || curr.second == n - 1) &&
                    (curr.first != entrance[0] || curr.second != entrance[1]) &&
                    (level < min_distance))
                {
                    min_distance = level;
                    while (!q.empty())
                        q.pop();
                    break;
                }
                else
                {
                    if (curr.first > 0 && maze[curr.first - 1][curr.second] == '.' && !vis[curr.first - 1][curr.second]){
                        q.push({curr.first - 1, curr.second});
                        vis[curr.first - 1][curr.second] = true;
                    }
                    if (curr.first < m - 1 && maze[curr.first + 1][curr.second] == '.' && !vis[curr.first + 1][curr.second]){
                        q.push({curr.first + 1, curr.second});
                        vis[curr.first + 1][curr.second] = true;
                    }
                    if (curr.second > 0 && maze[curr.first][curr.second - 1] == '.' && !vis[curr.first][curr.second - 1]){
                        q.push({curr.first, curr.second - 1});
                        vis[curr.first][curr.second - 1] = true;
                    }
                    if (curr.second < n - 1 && maze[curr.first][curr.second + 1] == '.' && !vis[curr.first][curr.second + 1]){
                        q.push({curr.first, curr.second + 1});
                        vis[curr.first][curr.second + 1] = true;
                    }
                }
                q.pop();
            }
            level++;
        }

        return min_distance == 10001 ? -1 : min_distance;
    }
};

int main()
{
    // vector<vector<char>> q{{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    // vector<vector<char>> q{{'+','+', '+', '+'}, {'+', '.', '.', '+'}, {'+', '.', '.', '+'}, {'+', '.', '.', '+'}, {'+', '+', '+', '+'}};
    vector<vector<char>> q{{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
    vector<int> ent{1, 2};
    Solution s;
    s.nearestExit(q, ent);
}