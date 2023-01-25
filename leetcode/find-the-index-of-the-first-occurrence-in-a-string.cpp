#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = 0;
        while (index < haystack.length()) {
            if (haystack[index] == needle[0]) {
                int offset = index;
                int offsetIndex = 0;
                bool flag = true;
                while (offsetIndex < needle.length()) {
                    if (haystack[offsetIndex + offset] != needle[offsetIndex]) {
                        flag = false;
                        break;
                    }
                    offsetIndex++;
                }
                if (flag){
                    return index;
                }
            }
            index++;
        }
        return -1;
    }
};

int main(){
    int i = (new Solution()) -> strStr("searchthestringfromthehere", "the");
    int j = (new Solution()) -> strStr("searchthestringfromthehere", "sepd");
    cout << i << " " << j;
}