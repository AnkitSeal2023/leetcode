#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int i=0, j=1, mask=0, cnt=0, maxCnt=1;
        int n = nums.size();
        while(i<n && j<n){
            if(i==j){
                j++;
                continue;
            }
            else if((nums[i]&nums[j])==0){
                mask|=nums[j];
                j++;
                cnt++;
                maxCnt=max(maxCnt, cnt);
            }
            else{
                mask^=nums[i];
                i++;
                if(cnt>0)  cnt--;
            }
        }
        // if(maxCnt>0)    return maxCnt;
        // return 1;
        return maxCnt;
    }
};