/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/merge-two-binary-trees/
 *  k := min(n, m)
 *  Time: O(k) 
 *  Space: O(logk) avg and O(k) for skewed tree
 *
*/

//   Definition for a binary tree node.
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
    void copyMergeTree(TreeNode *&root, TreeNode *src)
    {
        if (src)
        {
            if (!root)
            {
                root = new TreeNode(src->val);
            }
            else
            {
                root->val += src->val;
            }

            if (src->left)
            {
                copyMergeTree(root->left, src->left);
            }

            if (src->right)
            {
                copyMergeTree(root->right, src->right);
            }
        }
    }

    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        TreeNode *root = nullptr;

        copyMergeTree(root, root1);
        copyMergeTree(root, root2);

        return root;
    }

    TreeNode *mergeTrees2(TreeNode *r1, TreeNode *r2)
    {
        if (!r1 && !r2)
            return nullptr;

        int lhs = r1 ? r1->val : 0;
        int rhs = r2 ? r2->val : 0;

        TreeNode *t = new TreeNode(lhs + rhs);
        
        t->left = mergeTrees(r1 ? r1->left : nullptr, r2 ? r2->left : nullptr);
        t->right = mergeTrees(r1 ? r1->right : nullptr, r2 ? r2->right : nullptr);

        return t;
    }
};
