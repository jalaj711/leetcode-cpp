#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        x = x < 300 ? 300 : x;
        cout << x * 10 << endl;
    }
}