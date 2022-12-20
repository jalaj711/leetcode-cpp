#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void visit(vector<vector<int>> &rooms, vector<int> &queue, vector<bool> &visited)
{
}

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<bool> visited(rooms.size(), false);
        queue<int> queue;
        visited[0] = true;
        for (int i = 0; i < rooms[0].size(); i++)
        {
            if (!visited[rooms[0][i]])
            {
                queue.push(rooms[0][i]);
            }
        }
        int room;
        while (queue.size() != 0)
        {
            room = queue.front();
            visited[room] = true;
            for (int i = 0; i < rooms[room].size(); i++)
            {
                if (!visited[rooms[room][i]])
                {
                    queue.push(rooms[room][i]);
                }
            }
            queue.pop();
        }
        if(find(visited.begin(), visited.end(), false) != visited.end()){
            return false;
        }
        return true;
    }
};

int main()
{
    vector<vector<int>> vec;
    vector<int> vec1;
    vector<int> vec2;
    vector<int> vec3;
    vector<int> vec4;
    vec1.push_back(1);
    vec1.push_back(3);
    vec2.push_back(3);
    vec2.push_back(0);
    vec2.push_back(1);
    vec3.push_back(2);
    vec4.push_back(0);

    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    vec.push_back(vec4);

    (new Solution())->canVisitAllRooms(vec);
    return 0;
}