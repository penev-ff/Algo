/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 *  Time: O(N)
 *  Space: O(1)
 *
*/

#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {

        int l = 0, r = numbers.size() - 1;

        while (l < r)
        {
            int sum = numbers[l] + numbers[r];

            if (sum == target)
            {
                return {l + 1, r + 1};
            }

            if (sum > target)
            {
                --r;
            }
            else
            {
                ++l;
            }
        }

        return {0, 0};
    }
};
