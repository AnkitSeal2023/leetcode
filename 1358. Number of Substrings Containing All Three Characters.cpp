#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int i=0,j, count=0,n;
            n=s.size();
            unordered_map<int, int>mp;
            for(j=0; j<s.size(); j++){
                if(mp.size()==3){
                    break;
                }
                mp[s[j]]++;
            }
            if(mp.size()<3) return 0;
            j--;
            while(true){
                if(mp.size()==3){
                    if(j>=n)    break;
                    count+=n-j;
                }
                if(mp[s[i]]==1 && mp.size()==3){
                    mp.erase(s[i]);
                    i++;
                    j++;
                    if(j>=n)    break;
                    mp[s[j]]++;
                    continue;
                }
                if(mp[s[i]]>1 && mp.size()==3){
                    mp[s[i]]--;
                    i++;
                    continue;
                }
                else{
                    j++;
                    if(j>=n)    break;
                    mp[s[j]]++;
                }
            }
            return count;
        }
    };