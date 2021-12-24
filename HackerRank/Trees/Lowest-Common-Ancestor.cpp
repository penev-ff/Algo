/**
 * 
 *  Author: Ivan Penev
 *  Source: https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/
 *  Time: O(h) // h := height of tree
 *  Space: O(h)
 *
*/

/*The tree node has data, left child and right child */
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// NOTE: The problem's description allows a node to be a descendant of itself
Node *lca(Node *root, int v1, int v2)
{
    if (!root)
    {
        return nullptr;
    }

    if (root->data > v1 && root->data > v2)
    {
        // It's on the left side of the tree
        return lca(root->left, v1, v2);
    }

    if (root->data < v1 && root->data < v2)
    {
        // It's on the right side of the tree
        return lca(root->right, v1, v2);
    }

    return root;
}