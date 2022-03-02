/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/single-number/
 *  Time: O(k), k := number of set bits 
 *  Space: O(1)
 *
*/

#include <cstdint>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        uint32_t copyN = n;

        int count = 0;

        // Clear the least significant bit
        while (copyN)
        {
            copyN &= (copyN - 1);
            count++;
        }

        return count;
    }
};