#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int k = 100;
    while(k--) {
        if(a%k != 0 && b%k != 0 && c%k != 0){
            cout << k << endl;
            break;
        }
    }
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