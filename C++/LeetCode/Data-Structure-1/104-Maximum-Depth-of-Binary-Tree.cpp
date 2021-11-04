
/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 *  Time: O(n)
 *  Space: O(h)
 *
*/


#include <algorithm>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int leftDepth = 1 + maxDepth(root->left);
        int rightDepth = 1 + maxDepth(root->right);

        return std::max(leftDepth, rightDepth);

        // One-liner
        // return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};