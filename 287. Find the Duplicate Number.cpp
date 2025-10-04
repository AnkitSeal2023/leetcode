#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0], fast=nums[0];
        slow=nums[slow];
        fast=nums[fast];
        fast=nums[fast];
        while(true){
            if(slow==fast){
                //find the match here:
                fast=nums[0];
                while(true){
                    if(slow==fast){
                        return slow;
                    }
                    slow=nums[slow];
                    fast=nums[fast];
                }
            }
            else{
                slow=nums[slow];
                fast=nums[fast];
                fast=nums[fast];
            }
        }

    }
};