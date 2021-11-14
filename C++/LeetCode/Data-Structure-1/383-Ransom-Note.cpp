/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/ransom-note/
 *  Time: O(n + m)
 *  Space: O(1)
 * 
*/

#include <string>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    int letters[26] = {};
    for (char ch : magazine)
        ++letters[ch - 'a'];

    for (char ch : ransomNote)
    {
        if (letters[ch - 'a'] > 0)
            --letters[ch - 'a'];
        else
            return false;
    }

    return true;
}
