#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        float x, y, z;
        cin >> x >> y >> z;
        cout << (((x+y)/2 > z) ? "YES" : "NO") << endl;
    }
}