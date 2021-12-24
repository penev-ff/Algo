/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *  Time: O(2n) ~ O(n)
 *  Space: O(p), p := 255 
 *
*/

#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    static int lengthOfLongestSubstringOptimized(string s)
    {
        int left = 0, right = 0;

        int strLen = (int)s.length();

        bool set[256] = {
            false,
        };

        int maxSubstrLen = 0;

        while (right < strLen)
        {
            if (set[s[right]])
            {
                set[s[left]] = false;
                ++left;
            }
            else
            {
                set[s[right]] = true;

                maxSubstrLen = std::max(maxSubstrLen, right - left + 1);
                ++right;
            }
        }

        return maxSubstrLen;
    }

    int lengthOfLongestSubstring(string s)
    {
        int left = 0, right = 0;

        int strLen = (int)s.length();

        unordered_set<char> uSet;

        int maxSubstrLen = 0;

        while (right < strLen)
        {
            auto it = uSet.find(s[right]);
            if (it != uSet.end())
            {
                uSet.erase(s[left]);
                ++left;
            }
            else
            {
                uSet.insert(s[right]);
                maxSubstrLen = std::max(maxSubstrLen, (int)uSet.size());
                ++right;
            }
        }

        return maxSubstrLen;
    }
};
