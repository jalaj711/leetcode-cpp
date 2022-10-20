#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll int n, k, v;
    cin >> n >> k >> v;
    int sum = 0;
    for(int i=0;i<n;i++){
        int ai;
        cin >> ai;
        sum += ai;
    }
    int num = (v * (n + k) - sum);
    if(num % k == 0 && num > 0) {
        cout << num / k;
    } else {
        cout << -1;
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