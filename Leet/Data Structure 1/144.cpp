
/**
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/binary-tree-preorder-traversal/
 *  Time: O()
 *  Space: O()
 *
 * Given the root of a binary tree, 
 * return the preorder traversal of its nodes' values.
 * 
 *   
 *  Examples:
 * 
 *  Example 1:
 *  Input: root = [1,null,2,3]
 *  Output: [1,2,3]
 *
 *  Example 2:
 *
 *  Input: root = []
 *  Output: []
 *
 *  Example 3:
 *
 *  Input: root = [1]
 *  Output: [1]
 *
 *  Example 4:
 * 
 *  Input: root = [1,2]
 *  Output: [1,2]
 *
 *  Example 5:
 *
 *  Input: root = [1,null,2]
 *  Output: [1,2]
 *
 *  Constraints:
 *   The number of nodes in the tree is in the range [0, 100].
 *   -100 <= Node.val <= 100
 *
*/

#include <vector>
#include <iostream>

using namespace std;

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
    void preorderTraversalRec(TreeNode *root, vector<int> &preorder)
    {
        if (!root) return;

        preorder.push_back(root->val);
        preorderTraversalRec(root->left, preorder);
        preorderTraversalRec(root->right, preorder);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        if (root)
        {
            preorderTraversalRec(root, preorder);
        }

        return preorder;
    }
};