#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int count = 0;
    cin >> arr[0] >> arr[1];
    if (arr[0] != arr[1])
    {
        count += 2;
    }
    for (int i = 2; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] != arr[i - 1])
        {
            count++;
            if (arr[i - 1] == arr[i - 2])
            {
                count++;
            }
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