#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxSubArraySum(vector<int>& nums){
            int maxSum=0, sum1=0, sum2=0, minSum=0;
            for(int i=0; i<nums.size(); i++){
                sum1=sum1+nums[i];
                sum2=sum2+nums[i];
                maxSum=max(maxSum, sum1);
                if(sum1<=0){
                    sum1=0;
                }
                minSum=min(minSum, sum2);
                if(sum2>=0){
                    sum2=0;
                }
            }
            return max(maxSum, abs(minSum));
        }
        int maxAbsoluteSum(vector<int>& nums) {
            int maxSub=0;
            maxSub=maxSubArraySum(nums);
            return maxSub;
        }
    };