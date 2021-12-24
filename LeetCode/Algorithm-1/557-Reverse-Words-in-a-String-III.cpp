/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/reverse-words-in-a-string-iii/
 *  Time: O(n) 
 *  Space: O(1)
 *
*/

#include <string>

using namespace std;

class Solution
{
public:
    void reverseWord(string& s, int beg, int end)
    {
        while (beg < end)
        {
            std::swap(s[beg], s[end - 1]);
            beg++;
            end--;
        }
    }

    string reverseWords(string s)
    {
        int beg = 0, end = 0;
        while (end < s.length())
        {
            ++end;
            if (s[end] == ' ')
            {
                reverseWord(s, beg, end);
                beg = ++end;
            }
        }

        reverseWord(s, beg, end);

        return s;
    }
};
