
/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/path-sum/
 *  Time: O(n)
 *  Space: O(h)
 *
*/

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
    bool hasPathSumHelper(TreeNode *root, int targetSum, int currentSum)
    {
        if (!root)
            return false;

        currentSum += root->val;
        if (!root->left && !root->right && currentSum == targetSum)
        {
            return true;
        }

        return hasPathSumHelper(root->left, targetSum, currentSum) ||
               hasPathSumHelper(root->right, targetSum, currentSum);
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return hasPathSumHelper(root, targetSum, 0);
    }
};
