#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows= matrix.size();
        int cols= matrix[0].size();
        int total=rows*cols;
        int ctr=0, r=0, c=0, f_rows=0, f_cols=0, i,j;
        // c++, r++, c--, r--( < ctr--)  
        while(true){
            for(; c<cols; c++){
                res.push_back(matrix[r][c]);
                ctr++;
            }
            if(ctr==total)  break;
            c--;
            r++;
            for(; r<rows; r++){
                res.push_back(matrix[r][c]);
                ctr++;
            }
            if(ctr==total)  break;
            r--; 
            c--;
            for(; c>=f_cols;c--){
                res.push_back(matrix[r][c]);
                ctr++;
            }
            if(ctr==total)  break;
            c++;
            f_rows++;
            r--;
            for(; r>=f_rows; r--){
                res.push_back(matrix[r][c]);
                ctr++;
            }
            if(ctr==total)  break;
            r++;
            c++;
            cols--;
            rows--;
            f_cols++;
        }
        return res;
    }
};