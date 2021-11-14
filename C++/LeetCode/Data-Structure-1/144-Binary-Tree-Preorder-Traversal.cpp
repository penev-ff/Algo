
/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/binary-tree-preorder-traversal/
 *  Time: O(n)
 *  Space: O(1)
 *
*/

#include <vector>

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