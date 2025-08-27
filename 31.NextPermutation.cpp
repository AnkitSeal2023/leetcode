#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j=0, i=0;
        bool flag=false;
        int n=nums.size();
        if(n==1){
            return;
        }
        
        for(i=n-2; i>=0; i--){ 
            if(nums[i]<nums[i+1]){
                flag=true;
                break;
            }
        }
        if(!flag){
            reverse(nums.begin(), nums.end());
            return;
        }
        int ptr=i;
        // find the 1st element which is larger than nums[ptr], then swap
        for(j=n-1; j>i; j--){
            if(nums[j]>nums[ptr]){
                swap(nums[j], nums[ptr]);
                sort(nums.begin()+ptr+1,nums.end());
                return;
            }
        }
        return;
    }
};