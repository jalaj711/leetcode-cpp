#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int count = 0;
    if (s[0] == '1')
    {
        count++;
    }
    if (s[n - 2] == '0')
    {
        count++;
    }
    for (int i = 0; i < n - 2; i++)
    {
        if (s[i] == '0' && s[i + 1] == '1')
        {
            count++;
        }
    }
    cout << count << endl;
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