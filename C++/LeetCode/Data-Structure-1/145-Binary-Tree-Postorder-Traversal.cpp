
/**
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/binary-tree-postorder-traversal/
 *  Time: O()
 *  Space: O()
 *
 * Given the root of a binary tree, 
 * return the postorder traversal of its nodes' values.
 * 
 *   
 *  Examples:
 * 
 *  Example 1:
 *  Input: root = [1,null,2,3]
 *  Output: [3,2,1]
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
 *  Output: [2,1]
 *
 *  Example 5:
 *
 *  Input: root = [1,null,2]
 *  Output: [2,1]
 *
 *  Constraints:
 *   The number of nodes in the tree is in the range [0, 100].
 *   -100 <= Node.val <= 100
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