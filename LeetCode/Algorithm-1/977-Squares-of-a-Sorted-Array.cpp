/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/squares-of-a-sorted-array/
 *  Time: O(N)
 *  Space: O(1)
 *
*/

#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        const int N = nums.size();
        vector<int> result(N);

        int l = 0;
        int h = N - 1;

        for (int i = N - 1; i >= 0; --i)
        {
            int leftSquare = nums[l] * nums[l];
            int rightSquare = nums[h] * nums[h];

            if (leftSquare > rightSquare)
            {
                result[i] = leftSquare;
                ++l;
            } else {
                result[i] = rightSquare;
                --h;
            }
        }

        return result;
    }
};