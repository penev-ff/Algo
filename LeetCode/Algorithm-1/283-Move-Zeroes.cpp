/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/move-zeroes/
 *  Time: O(N)
 *  Space: O(1)
 *
*/

#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow = 0;
        for (size_t fast = 0; fast < nums.size(); fast++)
        {
            if (nums[fast] != 0)
            {
                std::swap(nums[fast], nums[slow]);
                ++slow;
            }
        }
    }
};