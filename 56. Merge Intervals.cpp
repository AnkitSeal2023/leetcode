#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &arr)
    {    
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        res.push_back(arr[0]);
        int last=0;
        int m = arr.size(); // no of rows
        int i;
        for (i = 1; i < m; i++)
        {
            if(arr[i][0]>res[last][1] ){ // jump
                res.push_back(arr[i]);
                last++;
            }
            else if((arr[i][0]>=res[last][0] && arr[i][0]<=res[last][1] && arr[i][1]>res[last][1]) || 
            (res[last][0]==res[last][1] && arr[i][0]>res[last][1])){ // extend 
                res[last][1]=arr[i][1];
            }
        }
        return res;
    }
};