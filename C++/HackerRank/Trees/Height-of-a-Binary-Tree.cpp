/**
 * 
 *  Author: Ivan Penev
 *  Source: https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/
 *  Time: O(n)
 *  Space: O(h)
 *
*/

#include <algorithm>

/* The tree node has data, left child and right child  */
struct Node
{
    int data;
    Node *left;
    Node *right;
};

int height(Node *root)
{
    if (!root)
    {
        return -1;
    }

    return std::max(height(root->left), height(root->right)) + 1;
}