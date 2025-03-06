#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long coloredCells(int n) {
            return 2*((long long)(n-1) * n);
        }
    };