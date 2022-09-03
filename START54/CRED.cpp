#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z;
        cin >> x;
        cin >> y;
        cin >> z;
        cout << x*4 + 2*y << endl;
    }
}