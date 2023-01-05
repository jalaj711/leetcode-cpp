#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a+b == c)
        cout << "YES";
    else
        cout << "NO";
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