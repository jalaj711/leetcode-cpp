#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n, k;
    cin >> n >> k;
    int votes[n] = {0};
    int winner_count = 0;
    for (int i = 0; i < n; i++)
    {
        int vote;
        cin >> vote;
        if (votes[vote - 1] != -1)
        {
            votes[vote - 1]++;
        }
        if (vote == i + 1)
        {
            votes[vote - 1] = -1;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (votes[j] >= k)
        {
            winner_count++;
        }
    }
    cout << winner_count << endl;
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