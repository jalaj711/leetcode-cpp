#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    long int n;
    cin >> n;
    long int a, b;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        if (j == 1)
        {
            a = i;
        }
        else if (j == n)
        {
            b = i;
        }
    }

    if (a < b)
    {
        cout << (a + n - b - 1);
    }
    else if (a > b)
    {
        cout << (a + n - b - 2);
    }

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