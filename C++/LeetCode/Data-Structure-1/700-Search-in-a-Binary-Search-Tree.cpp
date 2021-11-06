/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/search-in-a-binary-search-tree/
 *  Time: O(logN)
 *  Space: O(1)
 *
*/

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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root && root->val != val)
        {
            if (root->val > val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }

        return root;
    }
};