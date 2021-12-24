/**
 *
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/deepest-leaves-sum/
 *  Time: O(N)
 *  Space: O(H)
 * 
*/

#include <queue>

using namespace std;

/* Definition for a binary tree node. */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int deepestLeavesSum(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    queue<TreeNode *> wave;

    wave.push(root);

    int pushed = 1;
    int levelSum = 0;
    int lastLevelSum = 0;

    while (!wave.empty())
    {
        int toProcess = pushed;
        pushed = 0;
        while (toProcess)
        {
            TreeNode *curr = wave.front();
            wave.pop();

            levelSum += curr->val;

            if (curr->left)
            {
                wave.push(curr->left);
                ++pushed;
            }

            if (curr->right)
            {
                wave.push(curr->right);
                ++pushed;
            }

            --toProcess;
        }

        lastLevelSum = levelSum;
        levelSum = 0;
    }

    return lastLevelSum;
}

void deepestLeavesSumDFS(TreeNode *root, int &sum, int depth, int &maxdepth)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        if (depth == maxdepth)
        {
            sum += root->val;
        }
        else if (depth >= maxdepth)
        {
            sum = root->val;
            maxdepth = depth;
        }
    }

    deepestLeavesSumDFS(root->left, sum, depth + 1, maxdepth);
    deepestLeavesSumDFS(root->right, sum, depth + 1, maxdepth);
}

int deepestLeavesSumDFS(TreeNode *root)
{
    int maxdepth = 0;
    int sum = 0;
    deepestLeavesSumDFS(root, sum, 0, maxdepth);
    return sum;
}