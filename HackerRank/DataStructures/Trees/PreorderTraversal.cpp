/**
 * 
 *  Author: Ivan Penev
 *  Source: https://www.hackerrank.com/challenges/tree-preorder-traversal/
 *  Time: O(n)
 *  Space: O(h)
 *
*/

#include <iostream>
#include <stack>

using namespace std;

// Node is defined as
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// Iterative solution
void preorder(Node *root)
{
    if (root)
    {
        stack<Node *> stk;
        stk.push(root);

        while (!stk.empty())
        {
            Node *toProcess = stk.top();
            stk.pop();

            cout << toProcess->data << ' ';

            if (toProcess->right)
            {
                stk.push(toProcess->right);
            }

            if (toProcess->left)
            {
                stk.push(toProcess->left);
            }
        }
    }
}