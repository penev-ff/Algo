
/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/binary-tree-postorder-traversal/
 *  Time: O(n)
 *  Space: O()
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
    void postorderTraversalRec(TreeNode *root, vector<int> &postorder)
    {
        if (!root)
            return;

        postorderTraversalRec(root->left, postorder);
        postorderTraversalRec(root->right, postorder);

        postorder.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;
        if (root)
        {
            postorderTraversalRec(root, postorder);
        }

        return postorder;
    }
};