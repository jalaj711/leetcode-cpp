#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int count;
        cin >> count;
        int min;
        vector<int> numbers;
        for (int i = 0; i < count; i++)
        {
            int num;
            cin >> num;
            numbers.push_back(num);
            if (i == 0 || num < min)
            {
                min = num;
            }
        }
        int gcd = min;
        while (gcd > 1)
        {
            bool flag = false;
            for (int j = 0; j < count; j++)
            {
                if (numbers[j] % gcd != 0)
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
            gcd--;
        }
        for (int k = 0; k < count; k++)
        {
            cout << numbers[k] / gcd << " ";
        }
        cout << endl;
    }
}
