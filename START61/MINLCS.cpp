#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int reps_a[26] = { 0 };
    int reps_b[26] = { 0 };

    for(int i=0;i<n;i++){
        reps_a[a[i] - 97]++;
        reps_b[b[i] - 97]++;
    }
    int max_rep_count = min(reps_a[0], reps_b[0]);
    for(int j=1;j<26;j++){
        int rep = min(reps_a[j], reps_b[j]);
        if(rep > max_rep_count){
            max_rep_count = rep;
        }
    }
    cout << max_rep_count << endl;
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