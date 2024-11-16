#include <string>
#include <vector>
#include <array>
using namespace std;

// Straight forward solution high time complexity
// int lcs(string t1, int i, string t2, int j){
//     if(i == t1.length() || j == t2.length())
//         return 0;
//     else if (t1[i] == t2[j]) return 1 + lcs(t1, i+1, t2, j+1);
//     else return max(lcs(t1, i, t2, j+1), lcs(t1, i+1, t2, j));
// }

//class Solution
//{
//public:
//    int longestCommonSubsequence(string text1, string text2)
//    {
//        // array of length 1000 is used because that is the upper constraint
//        // in the problem and the initialization becomes easier that way.
//        vector<array<int, 1000>> table;
//        for (int i = 0; i < text1.length(); i++)
//        {
//            // intialize the table with all elements as 0
//            array<int, 1000> clmi = {0};
//            table.push_back(clmi);
//        }
//
//        // the concept here is that we loop through every element of text2
//        // for every element of text1. For each i,j table[i][j] represents
//        // the length of the LCS of text1[0:i] & text2[0:j]. If text1[i] &
//        // text2[j] match, we increment the value of table[i][j] by 1.
//        // Otherwise the value remains the same as previous lcs.
//        for (int i = 0; i < text1.length(); i++)
//        {
//            for (int j = 0; j < text2.length(); j++)
//            {
//                // if they are zero then the expression will result in an overflow
//                if (i != 0 && j != 0)
//
//                    // copy the length of the previous lcs
//                    table[i][j] = table[i - 1][j - 1];
//
//                if (text1[i] == text2[j])
//
//                    // one more matching pair
//                    table[i][j]++;
//
//                // if we are not at one of the boundaries
//                else if (i != 0 && j != 0)
//                    table[i][j] = max(table[i][j - 1], table[i - 1][j]);
//
//                // boundary on j axis
//                else if (i != 0 && j == 0)
//                    table[i][j] = table[i - 1][j];
//
//                // boundary on i axis
//                else if (i == 0 && j != 0)
//                    table[i][j] = table[i][j - 1];
//            }
//        }
//        return table[text1.length() - 1][text2.length() - 1];
//    }
//};

// Space optimised tabulation
class Solution {
public:
  int longestCommonSubsequence(const string &text1, const string &text2) {
    int n = text1.size();
    int m = text2.size();
    vector<int> prev (m+1, 0);
    vector<int> curr (m+1, 0);

    for(int i=n-1;i>=0;i--) {
      for (int j=m-1;j>=0;j--) {
        if (text1[i] == text2[j]) curr[j] = 1 + prev[j+1];
        else curr[j] = max(prev[j], curr[j+1]);
      }
      prev = curr;
    }

    return prev[0];
  }
};