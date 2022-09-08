#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int x, y;
    cin >> x >> y;
    cout << (x > y ? "NEW PHONE" : ( x < y ? "REPAIR" : "ANY"));
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