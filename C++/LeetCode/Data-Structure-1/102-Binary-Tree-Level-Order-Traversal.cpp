
/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/binary-tree-level-order-traversal/
 *  Time: O(n)
 *  Space: O(n)
 *
*/

#include <vector>
#include <queue>

using namespace std;

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> levelOrder;

        if (root)
        {
            queue<TreeNode *> wave;
            wave.push(root);

            vector<int> level;
            int waiting = 1;

            while (!wave.empty())
            {
                int waitingUpdated = 0;

                for (int i = 0; i < waiting; i++)
                {
                    TreeNode *toProcess = wave.front();
                    wave.pop();

                    level.push_back(toProcess->val);

                    if (toProcess->left)
                    {
                        wave.push(toProcess->left);
                        ++waitingUpdated;
                    }

                    if (toProcess->right)
                    {
                        wave.push(toProcess->right);
                        ++waitingUpdated;
                    }
                }

                waiting = waitingUpdated;
                levelOrder.push_back(level);
                level.clear();
            }
        }

        return levelOrder;
    }
};