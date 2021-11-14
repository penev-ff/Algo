/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/implement-queue-using-stacks/
 *  Time: O(1*) - Amortized constant
 *  Space: O(n)
 * 
*/

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

#include <stack>

class MyQueue
{
    std::stack<int> mainStack;
    std::stack<int> helperStack;
    int peekVal;

public:
    // O(1)
    void push(int x)
    {
        if (mainStack.empty())
            peekVal = x;

        mainStack.push(x);
    }

    // O(1*)
    int pop()
    {
        if (helperStack.empty())
        {
            while (!mainStack.empty())
            {
                helperStack.push(mainStack.top());
                mainStack.pop();
            }
        }

        int val = helperStack.top();
        helperStack.pop();

        if (!helperStack.empty())
            peekVal = helperStack.top();

        return val;
    }

    // O(1)
    int peek()
    {
        return peekVal;
    }

    // O(1)
    bool empty()
    {
        return mainStack.empty() && helperStack.empty();
    }
};