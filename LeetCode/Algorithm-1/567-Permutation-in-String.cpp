/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/permutation-in-string/
 *  Time: O(n)
 *  Space: O(1) only 2x26 elements are stored (constant)
 *
*/

#include <string>

using namespace std;

class Solution
{
public:
    bool isPermutation(int permutation[], int letters[])
    {
        const int SIZE = 26;
        for (int i = 0; i < SIZE; i++)
        {
            if (permutation[i] != letters[i])
            {
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
            return false;

        int letters[26] = {
            0,
        };

        for (char letter : s1)
        {
            ++letters[letter - 'a'];
        }

        // Sliding window
        int l = 0, r = 0;
        int permutation[26] = {
            0,
        };

        while (r <= s2.length())
        {
            if (r - l + 1 <= s1.length())
            {
                ++permutation[s2[r++] - 'a'];
            }
            else
            {
                if (isPermutation(permutation, letters))
                {
                    return true;
                }

                if (r == s2.length())
                {
                    return false;
                }

                --permutation[s2[l++] - 'a'];
                ++permutation[s2[r++] - 'a'];
            }
        }

        return false;
    }
};