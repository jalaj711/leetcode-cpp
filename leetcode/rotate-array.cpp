#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector <int> ans;
        if(k >= nums.size()){
            k = k % nums.size();
        }
        if(k == 0){
            return;
        }
        copy(nums.end() - k, nums.end(), back_inserter(ans));
        copy(nums.begin(), nums.end() - k, back_inserter(ans));
        nums.clear();
        copy(ans.begin(), ans.end(), back_inserter(nums));
    }
};


int main()
{
    vector<int> vec;
    vec.push_back(-5);
    vec.push_back(-2);
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(9);
    vec.push_back(15);

    (new Solution())->rotate(vec, 2);
    2;
}