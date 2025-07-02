/*
Ques: rotate a matrix by 90degree
Intuition:  1. Transpose the matrix
            2. Reverse the matrix
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void transpose(vector<vector<int>> &matrix)
    {
        int i = 0, j = 0, n = matrix.size();
        for (i = 0; i < n; i++)
        {
            for (j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void reverse(vector<vector<int>> &matrix)
    {
        int i = 0, j = 0, n = matrix.size();
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n/2; j++)
            {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
    void rotate(vector<vector<int>> &matrix)
    {
        transpose(matrix);
        reverse(matrix);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1}};
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << matrix[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    s.rotate(matrix);
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << matrix[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    return 0;
}