#include<vector>
using namespace std;

class Solution {
public:
  vector<int> par;
  vector<int> sz;

  // un-committed version of par and sz
  vector<int> upar;
  vector<int> usz;

  void init_dsu(int n) {
    par.resize(n);
    sz.resize(n, 1);
    usz.resize(n, 1);
    for(int i=0;i<n;i++) par[i] = i;
    upar = par;
  }
  int find(int u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
  }

  // find in uncommitted version
  int ufind(int u) {
    if (upar[u] == u) return u;
    return upar[u] = ufind(upar[u]);
  }

  void join(int u, int v) {
    int pu = find(u);
    int pv = find(v);

    if (pu == pv) return;
    if (sz[pu] > sz[pv]) {
      par[pv] = pu;
      sz[pu] += sz[pv];
    } else {
      par[pu] = pv;
      sz[pv] += sz[pu];
    }
  }

  // join in uncommitted version
  void ujoin(int u, int v) {
    int pu = ufind(u);
    int pv = ufind(v);

    if (pu == pv) return;
    if (usz[pu] > usz[pv]) {
      upar[pv] = pu;
      usz[pu] += usz[pv];
    } else {
      upar[pu] = pv;
      usz[pv] += usz[pu];
    }
  }
  vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
    init_dsu(n);
    vector<bool> ans;
    for (auto &req: requests) {
      ujoin(req[0], req[1]);

      bool success = true;
      // check for restrictions
      for (auto &res: restrictions) {
        if (ufind(res[0]) == ufind(res[1])) {
          success = false;
          break;
        }
      }
      ans.push_back(success);

      if (success) {
        // commit
        par = upar;
        sz = usz;
      } else {
        // uncommit
        upar = par;
        usz = sz;
      }
    }
    return ans;
  }
};