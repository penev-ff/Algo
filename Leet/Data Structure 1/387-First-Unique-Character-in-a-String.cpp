/**
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/ransom-note/
 *  Time: O(n + m)
 *  Space: O(1)
 * 
 *  Given two stings ransomNote and magazine,
 *  return true if ransomNote can be constructed
 *  from magazine and false otherwise.
 * 
 *  Each letter in magazine can only be used once
 *  in ransomNote.
 * 
 *  Examples:
 *
 *  Input: ransomNote = "a", magazine = "b"
 *  Output: false
 * 
 *  Input: ransomNote = "aa", magazine = "ab"
 *  Output: false
 * 
 *  Input: ransomNote = "aa", magazine = "aab"
 *  Output: true
 * 
 *  Constraints:
 *  1 <= ransomNote.length, magazine.length <= 105
 *  ransomNote and magazine consist of lowercase
 *  English letters.
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
