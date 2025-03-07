#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<bool> isPrime(right + 1, true);
        for (int p = 2; p * p <= right; p++)
        {
            if (isPrime[p] == true)
            {
                for (int i = p * p; i <= right; i += p)
                {
                    isPrime[i] = false;
                }
            }
        }
        int num1 = 0, num2 = 0, p1 = 0, p2 = 0, diff = INT_MAX;
        for (int i = left; i < right; i++)
        {
            if (isPrime[i] == true)
            {
                if (p1 == 0)
                {
                    p1 = i;
                    num1 = i;
                }
                else if (p2 == 0)
                {
                    p2 = i;
                    num2 = i;
                    if ((p2 - p1) < diff)
                    {
                        diff = p2 - p1;
                        num1 = p1;
                        num2 = p2;
                    }
                }
                else
                {
                    if ((i - p2) < diff)
                    {
                        diff = i - p2;
                        num1 = p2;
                        num2 = i;
                    }
                    p1 = p2;
                    p2 = i;
                }
            }
        }
        if (p1 == 0 || p2 == 0)
            return {-1, -1};
        return {num1, num2};
    }
};