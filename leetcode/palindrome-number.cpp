#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long long unsigned int reversed_num = 0;
        int x_copy = x;
        while (x != 0) {
            int remainder = x % 10;
            x = (x - remainder) / 10;
            reversed_num = reversed_num*10 + remainder;
        }

        if(reversed_num == x_copy) {
            return true;
        }
        return false;
    }
};

int main(){
    cout << (new Solution()) -> isPalindrome(121);
    cout << (new Solution()) -> isPalindrome(4567);
    cout << (new Solution()) -> isPalindrome(-7526);
    cout << (new Solution()) -> isPalindrome(1001);

}
