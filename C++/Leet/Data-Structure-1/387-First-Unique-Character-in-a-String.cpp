/**
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/first-unique-character-in-a-string/
 *  Time: O(n) - n ~ strlen
 *  Space: O(1) - we store an array of only 26 letters for counting
 *  
 *  Given a string s, find the first non-repeating character
 *  in it and return its index. If it does not exist, return -1.
 * 
 *  Examples:
 *
 *  Input: s = "leetcode"
 *  Output: 0
 * 
 *  Input: s = "loveleetcode"
 *  Output: 2
 * 
 *  Input: s = "aabb"
 *  Output: -1
 * 
 *  Constraints:
 *   1 <= s.length <= 105
 *   s consists of only lowercase English letters.
 *
*/

#include <string>
#include <unordered_map>

using namespace std;

int firstUniqCharMap(string s)
{
    unordered_map<char, int> uMap;

    for (int i = 0; i < s.length(); ++i)
        ++uMap[s.at(i)];

    for (int i = 0; i < s.length(); ++i)
    {
        int letter = s.at(i);
        if (uMap[letter] == 1)
            return i;
    }

    return -1;
}

// Better approach
int firstUniqCharArray(string s)
{
    const size_t LETTERS_COUNT = 26;
    int letters[LETTERS_COUNT] = {};

    for (char ch : s)
        ++letters[ch - 'a'];

    for (int i = 0; i < s.length(); ++i)
        if (letters[s[i] - 'a'] == 1)
            return i;

    return -1;
}

int main()
{
    firstUniqCharArray("leetcode");

    return 0;
}
