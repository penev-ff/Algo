/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/search-insert-position/
 *  Time: O(logn)
 *  Space: O(1)
 *
*/

#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0, r = (int)nums.size() - 1;
        int m;
        while (l <= r)
        {
            m = r - (r - l) / 2;

            if (nums[m] == target)
            {
                return m;
            }

            if (nums[m] > target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        return l;
    }
};