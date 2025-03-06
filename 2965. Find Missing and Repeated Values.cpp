#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            unordered_map<int,int> mp;
            int n=grid.size();
            int x= n*n;
            int a,b, sum=0, sn;
            sn=(x*(x+1))/2;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    mp[grid[i][j]]++;
                    if(mp[grid[i][j]]==2){
                        a=grid[i][j];
                    }
                    sum+=grid[i][j];
                }
            }
            b=sn+a-sum;
            vector<int> res({a,b});
            return res;
        }
    };