/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/binary-search/
 *  Time: O(logn)
 *  Space: O(1)
 *
*/

#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
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

        return -1;
    }
};