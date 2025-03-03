#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> less, equal, greater, res;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]>pivot){
                    greater.push_back(nums[i]);
                }
                else if(nums[i]<pivot){
                    less.push_back(nums[i]);
                }
                else if(nums[i]== pivot){
                    equal.push_back(nums[i]);
                }
            }
            // res.insert(res.end(), less.begin(), less.end());
            less.insert(less.end(), equal.begin(), equal.end());
            less.insert(less.end(), greater.begin(), greater.end());
            return less;
        }
    };
    
// SOLUTION 2: counts the number of elements less than pivot and greater than pivot

class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int lessCount=0, highCount=0, equalCount=0;
            for(auto x: nums){
                if(x<pivot) lessCount++;
                if(x>pivot) highCount++;
                if(x==pivot)    equalCount++;
            }
            vector<int> res(nums.size());
            int i=0, j=nums.size()-highCount, k ,a=0;
            k=nums.size()-highCount-equalCount;
            while(a<nums.size())        {
                if(nums[a]<pivot){
                    res[i]=nums[a];
                    i++;
                }
                if(nums[a]>pivot){
                    res[j]=nums[a];
                    j++;
                }
                if(nums[a]==pivot){
                    res[k]=nums[a];
                    k++;
                }
                a++;
            }
            return res;
        }
    };