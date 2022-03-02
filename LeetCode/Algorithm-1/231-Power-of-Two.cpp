/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/power-of-two/
 *  Time: O(1)
 *  Space: O(1)
 *
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {    
        return (n <= 0 ? false : !(n & (n-1)));
    }
};