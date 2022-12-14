#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, p, q;
        cin >> x;
        cin >> p;
        cin >> q;
        cout << x*(p-q) << endl;
    }
}