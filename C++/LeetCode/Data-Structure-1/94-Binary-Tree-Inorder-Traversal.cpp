
/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/binary-tree-inorder-traversal/
 *  Time: O(n)
 *  Space: O()
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
    void inorderTraversalRec(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
            return;

        inorderTraversalRec(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversalRec(root->right, inorder);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;
        if (root)
        {
            inorderTraversalRec(root, inorder);
        }

        return inorder;
    }
};