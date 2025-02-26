class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int sum = 0;
        long count = 0;
        vector<int> arr2 = arr;
        int n = arr2.size();
        for (int i = 0; i < arr2.size(); i++)
        {
            sum = sum + arr2[i];
            arr2[i] = sum;
        }
        for (int i = -1; i < arr2.size(); i++)
        {
            for (int j = n - 1; j >= i; j--)
            {
                sum = arr2[j] - arr2[i];

                if (sum % 2 != 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
};