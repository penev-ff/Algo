/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/first-bad-version/
 *  Time: O(logn)
 *  Space: O(1)
 *
*/

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 0, r = n;
        int m;
        while (l < r)
        {
            m = l - (l - r) / 2;

            if (isBadVersion(m))
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }

        return l;
    }
};