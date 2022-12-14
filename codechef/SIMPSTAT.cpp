#include <bits/stdc++.h>
using namespace std;

#define ll long double

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> arr;
    for (int i = 0; i < n; i++)
    {
        ll ai;
        cin >> ai;
        arr.push_back(ai);
    }

    sort(arr.begin(), arr.end());

    ll sum = 0;
    for (int j = k; j < n - k; j++)
    {
        sum += arr[j];
    }

    ll answer = sum / (n - 2 * k);

    cout << fixed << setprecision(6) << answer << endl;
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