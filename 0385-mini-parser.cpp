#include<vector>
#include<string>
using namespace std;

class NestedInteger {
    public:
      // Constructor initializes an empty nested list.
      NestedInteger();

      // Constructor initializes a single integer.
      NestedInteger(int value);

      // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;

      // Set this NestedInteger to hold a single integer.
      void setInteger(int value);

     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
      void add(const NestedInteger &ni);
       // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
  };

class Solution {
public:
  NestedInteger parse(const string &s, int * ptr) {

    bool isArr = false;
    NestedInteger n;
    if (s[*ptr] == '[') {
      (*ptr)++;
      isArr = true;
    }

    while ((*ptr) < s.size() && s[*ptr] != ']') {
      if (s[*ptr] == '[') {
        n.add(parse(s, ptr));
      } else if (s[*ptr] == ',') {
        (*ptr)++;
      } else {
        int z = 0;
        bool neg = s[*ptr] == '-';
        if (neg) (*ptr)++;

        while (s[*ptr] >= '0' && s[*ptr] <= '9') {
          z = z*10 + (s[(*ptr)++] - '0');
        }

        if (neg) z = -z;

        if (!isArr) {
          n.setInteger(z);
        } else {
          NestedInteger n1(z);
          n.add(n1);
        }
      }
    }
    (*ptr)++;
    return n;
  }
  NestedInteger deserialize(string s) {
    int p = 0;
    return parse(s, &p);
  }
};