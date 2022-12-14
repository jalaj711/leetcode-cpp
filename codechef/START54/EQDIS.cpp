#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> distinct;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            distinct[a]++;
        }

        if (distinct.size() % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else if (distinct.size() < n)
        {
            cout << "YES" << endl;
        }
        else
        {

            cout << "NO" << endl;
        }
    }
}