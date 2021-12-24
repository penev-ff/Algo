/**
 * 
 *  Author: Ivan Penev
 *  Source: https://www.hackerrank.com/challenges/tree-inorder-traversal/
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

void inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << ' ';
        inOrder(root->right);
    }
}