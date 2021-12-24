/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/reverse-string/
 *  Time: O(n) 
 *  Space: O(1)
 *
*/

#include <vector>

using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        size_t len = s.size();
        for (int i = 0; i < len / 2; i++)
            std::swap(s[i], s[len - i - 1]);        
    }
};