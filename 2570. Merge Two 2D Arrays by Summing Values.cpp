#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            int n1=nums1.size();
            int n2=nums2.size();
            if(n2 > n1){
                swap(nums2, nums1);
                swap(n2,n1);
            }
            unordered_map<int,int> mp1;
            unordered_map<int,int> mp2;
            vector<vector<int>> res;
            vector<int> val(2);
            int j=0;
            for( auto x: nums1){
                mp1[x[0]]=x[1];
            }
            for( auto x: nums2){
                mp2[x[0]]=x[1];
            }
            for(int i=0; i<=1000; i++){
                if(mp1[i]!=0 || mp2[i]!=0){
                    if(mp1[i]!=0 && mp2[i]!=0){
                        val[0]=i;
                        val[1]=mp1[i]+mp2[i];
                        res.push_back(val);
                    }
                    else if(mp1[i]!=0){
                        val[0]=i;
                        val[1]=mp1[i];
                        res.push_back(val);    
                    }
                    else if(mp2[i]!=0){
                        val[0]=i;
                        val[1]=mp2[i];
                        res.push_back(val);    
                    }
                }
            }
            return res;
        }
    };