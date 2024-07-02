#include <stdlib.h>
class Solution1
{
public:
    int reverse(int x)
    {
        int *ans = (int *)malloc(sizeof(int));
        *ans = 0;
        bool isNegative = false;
        if (x <= -2147483647)
            return 0;
        if (x < 0)
        {
            isNegative = true;
            x = -x;
        }
        while (x > 0)
        {
            if (*ans < 0)
                return 0;
            *ans = (*ans) * 10;
            *ans = (*ans) + x % 10;
            x /= 10;
        }
        if (isNegative)
            *ans = -*ans;
        return *ans;
    }
};

class Solution
{
public:
    int reverse(int x)
    {
        int ans = 0;
        bool isNegative = false;
        if (x <= -2147483647)
            return 0;
        if (x < 0)
        {
            isNegative = true;
            x = -x;
        }
        while (x > 0)
        {
            if (ans >= 214748365 || (ans >= 214748364 && x % 10 > 7))
                return 0;
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        if (isNegative)
            ans = -ans;
        return ans;
    }
};

int main()
{
    (new Solution())->reverse(1534236469);
    (new Solution())->reverse(1463847412);
    (new Solution())->reverse(-123);
    (new Solution())->reverse(504781);
}