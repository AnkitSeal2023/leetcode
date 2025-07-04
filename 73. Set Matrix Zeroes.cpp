#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int i = 0, j = 0;
        int m = matrix.size();    // no of rows
        int n = matrix[0].size(); // no of cols
        unordered_map<int, int> rows;
        unordered_map<int, int> columns;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows[i] = 1;
                    columns[j] = 1;
                }
            }
        }
        for (auto x : rows)
        { // setting a whole row as 0
            for (int k = 0; k < n; k++)
            {
                matrix[x.first][k] = 0;
            }
        }
        for (auto x : columns)
        { // setting a whole col as 0
            for (int k = 0; k < m; k++)
            {
                matrix[k][x.first] = 0;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix;
    matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    int m = matrix.size();    // no of rows
    int n = matrix[0].size(); // no of cols
    for (int i = 0; i <m; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    s.setZeroes(matrix);
    cout<<endl;
    for (int i = 0; i <m; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}