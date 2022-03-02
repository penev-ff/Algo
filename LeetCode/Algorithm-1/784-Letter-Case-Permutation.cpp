/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/letter-case-permutation/
 *  Time: O(2^n) 
 *  Space: O(n)
 *
*/

#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> letterCasePermutation(string s)
    {
        vector<string> permutations;
        backtrack(permutations, 0, s);

        return permutations;
    }

    bool isLetter(char ch)
    {
        return (ch >= 'a' && ch <= 'z') ||
               (ch >= 'A' && ch <= 'Z');
    }

    char revertLetterCase(char ch)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            return ch + 'A' - 'a';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            return ch + 'a' - 'A';
        }

        return ch;
    }

    void backtrack(
        vector<string> &permutations,
        int pos,
        string &input)
    {
        if (pos == input.size())
        {
            permutations.push_back(input);
        }
        else
        {
            char ch = input[pos];

            if (isLetter(ch))
            {
                input[pos] = revertLetterCase(ch);
            }
            
            backtrack(permutations, pos + 1, input);

            // Reset the original
            if (isLetter(ch))
            {
                input[pos] = ch;
                backtrack(permutations, pos + 1, input);
            }
        }
    }
};

int main()
{
    string s = "3z4";

    Solution sol;

    sol.letterCasePermutation(s);

    return 0;
}