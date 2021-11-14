/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/insert-into-a-binary-search-tree/
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
TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode **runner = &root;

        while (*runner)
        {
            if ((*runner)->val > val)
            {
                runner = &(*runner)->left;
            }
            else
            {
                runner = &(*runner)->right;
            }
        }

        *runner = new TreeNode(val);

        return root;
    }
};