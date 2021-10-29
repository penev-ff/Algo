/**
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/valid-anagram/
 *  Time: O(n)
 *  Space: O(1)
 *  
 *  Given two strings s and t, return true 
 *  if t is an anagram of s, and false otherwise.
 * 
 *  Examples:
 *  Input: s = "anagram", t = "nagaram"
 *  Output: true
 * 
 *  Input: s = "rat", t = "car"
 *  Output: false
 * 
 *  Constraints:
 *  1 <= s.length, t.length <= 5 * 104
 *  s and t consist of lowercase English letters.
 * 
*/

#include <iostream>

using namespace std;

bool isAnagram(string s, string t)
{
    // If lengths are not equal,
    // strings cannot be anagrams
    if (s.length() != t.length())
        return false;

    // A map like structure to store the
    // letters count. In our case - lowercase English letters.
    const int ALPHABET_SIZE = 26;
    int letters[ALPHABET_SIZE] = {}; // 4B = 32 bit =  [2^31, 2 ^ 31 - 1]

    // Lengths are equal
    size_t n = s.length();

    // Increase/Decrease each letter's count based on the strings
    for (size_t i = 0; i < n; ++i)
    {
        ++letters[s[i] - 97];
        --letters[t[i] - 97];
    }

    // If any letter count is not zero, then the strings are not anagrams
    for (int c : letters)
    {
        if (c != 0)
            return false;
    }

    return true;
}

int main()
{
    isAnagram("anagram", "nagaram");

    return 0;
}