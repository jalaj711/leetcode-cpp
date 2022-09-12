#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    cout << x * 2 * (n + m);
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}