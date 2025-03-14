#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries, int x)
    {
        int n=nums.size();
        vector<int> num2(n,0);
        for(int i = 0; i <= x; i++)
        {
            num2[queries[i][0]] += queries[i][2];
            if(queries[i][1]+1<n){
                num2[queries[i][1]+1] -= queries[i][2];
            }
        }
        int sum=0;
        for(int i = 0; i < n; i++){
            sum+=num2[i];
            if(sum<nums[i]){
                return false;
            }
        } 
        return true;
    }
    bool isZeroInput(vector<int>& nums){
        for(auto x: nums){
            if(x!=0){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        if(isZeroInput(nums))   return 0;
        int n = nums.size(), l=0, r=queries.size()-1;
        int mid = l+(r-l)/2, k=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(isZeroArray(nums, queries, mid)){
                k=mid+1;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return k;
    }
};