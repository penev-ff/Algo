/**
 *  Author: Ivan Penev
 *  Source: 
 *  Time: O(n)
 *  Space: O(k), k := count of opened brackets
 * 
 * Given a string s containing just the characters 
 * '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 *  Open brackets must be closed by the same type of brackets.
 *  Open brackets must be closed in the correct order.
 *  
 * 
 *  Examples:
 * Input: s = "()"
 * Output: true
 * 
 * Input: s = "()[]{}"
 * Output: true 
 * 
 * Input: s = "(]"
 * Output: false
 * 
 * Input: s = "([)]"
 * Output: false
 * 
 * Input: s = "{[]}"
 * Output: true
 * 
 *  Constraints:
 * 1 <= s.length <= 104
 * s consists of parentheses only '()[]{}'.
 * 
*/

#include <stack>
#include <string>

bool isOpeningBracket(char ch)
{
    return ch == '{' || ch == '(' || ch == '[';
}

char getClosingBracket(char ch)
{
    switch (ch)
    {
    case '{':
        return '}';
    case '(':
        return ')';
    case '[':
        return ']';
    default:
        return '?';
    }
}

bool isValid(std::string s)
{
    std::stack<char> wave;

    for (char ch : s)
    {
        if (isOpeningBracket(ch))
        {
            wave.push(ch);
        }
        else if (!wave.empty() && ch == getClosingBracket(wave.top()))
        {
            wave.pop();
        }
        else
        {
            return false;
        }
    }

    return wave.empty();
}

int main()
{

    return 0;
}