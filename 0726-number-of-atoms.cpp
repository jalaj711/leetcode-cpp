#include<map>
#include<string>

using namespace std;

class Solution {
private:
    map<string, int> _countAtoms(string formula) {
        map<string, int> count;
        for(int i=0;i<formula.size();) {
            if (formula[i]=='(') {
                string running = "";
                int open = 0;
                i++;
                while(i<formula.size()) {
                    if (formula[i] == '(') open++;
                    else if (formula[i] == ')' && --open == -1) break;
                    running += formula[i];
                    i++;
                }
                i++;
                int rep = 0;
                while (i<formula.size() && formula[i] >= '0' && formula[i] <= '9') {
                    rep = rep * 10 + (formula[i] - '0');
                    i++;
                }
                rep = rep == 0 ? 1 : rep;
                map<string,int> temp = _countAtoms(running);
                for (auto it=temp.begin();it!=temp.end();it++) {
                    count[it->first] += (it->second) * rep;
                }
            } else {
                string running = "";
                running += formula[i];
                i++;
                while(i<formula.size()&&formula[i]>='a'&&formula[i]<='z') {
                    running += formula[i];
                    i++;
                }
                int rep = 0;
                while (i<formula.size() && formula[i] >= '0' && formula[i] <= '9') {
                    rep = rep * 10 + (formula[i] - '0');
                    i++;
                }
                rep = rep == 0 ? 1 : rep;
                count[running] += rep;
            }
        }
        return count;
    }
public:
    string countOfAtoms(string formula) {
        map<string, int> mp = _countAtoms(formula);
        string ans = "";
        for (auto it=mp.begin();it!=mp.end();it++) {
            ans += it -> first;
            if (it->second != 1) ans += to_string(it->second);
        }
        return ans;
    }
};