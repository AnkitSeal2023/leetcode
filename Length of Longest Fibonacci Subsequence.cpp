#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void findSeq(vector<int> arr, unordered_map<int, int> mp, int a, int b, int count, int &maxCount)
    {
        if (a >= arr.size() || b >= arr.size())
        {
            return;
        }
        int j;
        for (; b < arr.size(); b++)
        {
            if (mp[arr[a] + arr[b]] != 0)
            {
                count++;
                maxCount = max(maxCount, count);
                cout<<"a:"<<a<<"    b:"<<b<<endl;
                int x=mp[arr[a] + arr[b]];
                cout<<"x:"<<x<<endl;
                findSeq(arr, mp, b, mp[arr[a] + arr[b]], count, maxCount);
                count=0;
            }
            else{

            }
        }
    }
    int lenLongestFibSubseq(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        for (int x = 0; x < arr.size(); x++)
        {
            mp[arr[x]] = x;
            cout<<"arr[x]="<<arr[x]<<"  mp[arr[x]]="<<mp[arr[x]]<<endl;
        }
        int maxCount=0;
        for(int i=0; i<arr.size(); i++){
            findSeq(arr, mp, i, i+1, 0, maxCount);
        }
        if(maxCount)    return maxCount+2;
        return maxCount;
    }
};

