#include<string>
#include<vector>
using namespace std;

class Solution {
public:
  int findClosing(const string &expr, int i) {
    int b = 0, n = expr.size();
    while(i < n) {
      if (expr[i] == '(') b++;
      else if (expr[i] == ')') b--;

      if (b == 0) break;
      i++;
    }
    return i;
  }
  bool solve(const string &expr, int &i) {
    char op = expr[i++];
    int j = findClosing(expr, i);
    vector<bool> arg;
    i++;
    while(i < j) {
      if (expr[i] == 't') arg.push_back(true);
      else if (expr[i] == 'f') arg.push_back(false);
      else if (expr[i] != ',')  arg.push_back(solve(expr, i));
      i++;
    }

    bool ans = arg[0];
    if (op == '!') return !ans;
    for(int k=1;k<arg.size();k++) {
      if (op == '|') ans |= arg[k];
      else ans &= arg[k];
    }
    return ans;
  }
  bool parseBoolExpr(const string &expr) {
    if (expr.size() == 1) return expr=="t";
    int i = 0;
    return solve(expr, i);
  }
};