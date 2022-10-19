#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    bool is_a_odd = a % 2 != 0;
    bool is_b_odd = b % 2 != 0;
    bool is_c_odd = c % 2 != 0;
    if((is_a_odd && is_b_odd && is_c_odd) || (!is_a_odd && !is_b_odd && !is_c_odd)){
        cout << "no";
    } else {
        cout << "yes";
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