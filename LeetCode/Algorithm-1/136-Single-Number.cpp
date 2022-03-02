/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/single-number/
 *  Time: O(n) 
 *  Space: O(1)
 *
*/

#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int x = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            x ^= nums[i];
        }

        return x;
    }
};