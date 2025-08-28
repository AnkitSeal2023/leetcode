#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if(n==1)    return 0;
        int diff=0, min=0, p1=0, p2=0, min_idx=0, max_idx=0;
        for(int i=1; i<n; i++){
            if(arr[i]-arr[min_idx] > diff){
                p2=i;
                p1=min_idx;
                diff=arr[i]-arr[min_idx];
                max_idx=i;
            }
            if(arr[i]<arr[min_idx]){
                min_idx=i;
            }
        }
        return arr[p2]-arr[p1];
    }
};