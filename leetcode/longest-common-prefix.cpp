#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if(strs.size() > 0) {
            string max = strs[0];
            for (int i = 1; i < strs.size();i++){
                for(int j=0;j<max.length();j++){
                    if(max[j] != strs[i][j]){
                        max = max.substr(0, j-1);
                        if(max == "") {
                            break;
                        }
                    }
                }if(max == "") {
                            break;
                        }
            }
            return max;
        }
        return "";
    }
};