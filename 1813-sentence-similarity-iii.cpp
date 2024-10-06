#include <string>

using namespace std;

class Solution {
public:
  bool areSentencesSimilar(string s1, string s2) {
    int p1 = 0, p2 = 0, // pointers
        n1 = s1.size(), // size
        n2 = s2.size(),
        cp, cs; // common prefix and common suffix
    string t1, t2; // temp string

    while (p1 < n1 && p2 < n2) {
      t1 = "";
      t2 = "";

      while (p1 < n1 && s1[p1] != ' ') {
        t1 += s1[p1];
        p1++;
      }

      while (p2 < n2 && s2[p2] != ' ') {
        t2 += s2[p2];
        p2++;
      }
      p1++;
      p2++;

      if (t1 == t2) cp = p1;
      else break;

    }

    p1 = n1 - 1;
    p2 = n2 - 1;

    while (p1 >= 0 && p2 >= 0) {
      t1 = "";
      t2 = "";

      while (p1 >= 0 && s1[p1] != ' ') {
        t1 += s1[p1];
        p1--;
      }

      while (p2 >= 0 && s2[p2] != ' ') {
        t2 += s2[p2];
        p2--;
      }

      p2--;
      p1--;

      if (t1 == t2) cs = n1 - p1 - 1;
      else break;

    }
    return (cp + cs >= n1) || (cp + cs >= n2);

  }
};