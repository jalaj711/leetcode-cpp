#include <bits/stdc++.h>
using namespace std;

#define ll long long

int solve()
{
    int w, x, y, z;
    cin >> w >> x >> y >> z;
    if (w == x || w == y || w == z || w == x + y || w == x + z || w == y + z || w == x + y + z)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
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