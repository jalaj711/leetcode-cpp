#include<vector>

using namespace std;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries,
                                     int x) {
        vector<int> pos;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == x)
                pos.push_back(i);

        for (int i = 0; i < queries.size(); i++)
            if (queries[i] > pos.size())
                queries[i] = -1;
            else
                queries[i] = pos[queries[i] - 1];

        return queries;
    }
};