#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, long long n)
    {
        if (n == 0)
            return 1.00;
        if (n == 1)
            return x;
        else if (n < 0)
            return 1.00 / (myPow(x, abs(n)));
        else if (n > 0)
        {
            if (n % 2 == 0)
            {
                return 1.00 * myPow(x * x, n / 2);
            }
            else
            {
                return x * myPow(x * x, (n - 1) / 2);
            }
        }
        return 0.00;
    }
};