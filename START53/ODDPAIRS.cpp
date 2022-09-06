#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;

    int n_even, n_odd;
    if (n % 2 == 0)
    {
        n_even = n / 2;
    }
    else
    {
        n_even = (n - 1) / 2;
    }

    n_odd = n - n_even;

    cout << 2 * n_even * n_odd;
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