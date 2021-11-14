/**
 * 
 *  Author: Ivan Penev
 *  Source: https://www.hackerrank.com/challenges/tree-postorder-traversal/
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

void postorder(Node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << ' ';
    }
}