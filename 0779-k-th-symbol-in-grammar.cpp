#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Solution
{

public:
    int kthGrammar(int n, int k)
    {
        if (n == 1)
            return 0;
        int number = 1 << (n - 1);
        if (k <= number / 2)
            return kthGrammar(n - 1, k);
        return kthGrammar(n - 1, k - number / 2) ? 0 : 1;
    }
};

int main()
{
    Solution s;
    for (int i = 1; i <= 32; i++)
    {
        cout << s.kthGrammar(6, i);
    }
    cout << endl;
}