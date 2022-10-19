#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    string bin;
    cin >> bin;
    int count = 0;
    for(int i=1;i<n;i++){
        if(bin[i] == bin[i-1]){
            count++;
        }
    }
    cout << count;
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