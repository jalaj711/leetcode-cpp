#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    int count = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int j = 0; j < n; j++)
    {
        int sum = 0, product = 1;
        for(int k=j;k<n;k++){
            sum += arr[k];
            product *= arr[k];
            if(sum == product){
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