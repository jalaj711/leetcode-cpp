    #include <bits/stdc++.h>
    using namespace std;

    #define ll long long

    void solve()
    {
        int w, x, y, z;
        cin >> w >> x >> y >> z;
        cout << w + (x - y) * z;
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