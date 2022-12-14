#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    float a, x, b, y;
    cin >> a >> x >> b >> y;
    cout << (a / x > b / y ? "ALICE" : (a / x < b / y ? "BOB" : "EQUAL"));
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