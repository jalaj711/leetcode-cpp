#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) {
            return 0;
        }
        int pointer_one = 0, pointer_two = 0;
        while (pointer_two < nums.size()) {
            if (nums[pointer_two] != val ) {
                if(pointer_one != pointer_two) {
                    swap(nums[pointer_one], nums[pointer_two]);
                }
                pointer_one++;
            }
            pointer_two++;
        }
        return pointer_one + 1;
    }
};

int main() {
    vector<int> test;
    test.push_back(0);
    test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    test.push_back(2);
    test.push_back(2);
    test.push_back(3);
    test.push_back(6);
    test.push_back(6);
    (new Solution()) -> removeElement(test, 2);
}
