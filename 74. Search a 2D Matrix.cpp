#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool binarySearch(vector<int> &nums, int key)
    {
        int low = 0, high = nums.size() - 1;
        if (key < nums[low] || key > nums[high])
            return false;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == key)
            {
                return true;
            }
            else if (nums[mid] > key)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int high = rows - 1;
        int low = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (high == 0 && low == 0)
            {
                return binarySearch(matrix[mid], target);
            }
            if (target <= matrix[mid][cols - 1])
            {
                if ((target == matrix[mid][cols - 1]) || (mid==0 && target <= matrix[mid][cols - 1]) || (mid != 0 && target > matrix[mid - 1][cols - 1]))
                {
                    return binarySearch(matrix[mid], target);
                }
                else if (target <= matrix[mid - 1][cols - 1])
                {
                    high = mid - 1;
                }
            }
            else if (target > matrix[mid][cols - 1])
            {
                low = mid + 1;
            }
        }
        return false;
    }
};