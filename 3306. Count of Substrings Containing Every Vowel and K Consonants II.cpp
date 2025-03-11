#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countOfSubstrings(string word, int k)
    {
        unordered_map<char, int> v_mp;
        int i=0,c_count=0, c_ptr, ptr1, ptr2, v_count=0;
        bool c_flag=false, v_flag=false;
        while(true){ //find 1st window
            if(word[i]=='a' || word[i]=='e' ||word[i]=='i' ||word[i]=='o' ||word[i]=='u'){
                v_count++;
                v_mp[word[i]]++;
            }
            else{
                if(c_flag==false){
                    c_ptr=i;
                }
                c_count++;
                c_flag=true;
                if(c_count==k){
                    ptr2=i;
                    for(auto x: v_mp){
                        if(x.second==0){
                            continue;
                        }
                    }
                }
                else if(c_count>k){
                    if(word[ptr1]=='a' || word[ptr1]=='e' ||word[ptr1]=='i' ||word[ptr1]=='o' ||word[ptr1]=='u')
                    {
                        if(word[i]=='a' || word[i]=='e' ||word[i]=='i' ||word[i]=='o' ||word[i]=='u')
                        v_mp[word[ptr1]]--;
                    }
                }
            }
            i++;
        }
    }
};