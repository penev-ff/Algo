/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/valid-parentheses/
 *  Time: O(n)
 *  Space: O(k), k := count of opened brackets
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