#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n, b;
    cin >> n >> b;
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        int w, h, p;
        cin >> w >> h >> p;
        if (p <= b && w * h > max)
        {
            max = w * h;
        }
    }
    if(max == -1){
        cout << "no tablet";
    } else {
        cout << max;
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