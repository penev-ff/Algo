/**
 * 
 *  Author: Ivan Penev
 *  Source: https://www.hackerrank.com/challenges/tree-top-view/
 *  Time: O(n)
 *  Space: O(h)
 *
*/

#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d, Node *left = nullptr, Node *right = nullptr)
        : data(d), left(left), right(right) {}
};

void topView(Node *root)
{
    if (root)
    {
        // Keep all top view nodes in inorder manner 
        map<int, int> topNodes;

        // Perform BFS to find all top view nodes
        queue<pair<Node *, int>> wave;
        wave.push({root, 0});

        while (!wave.empty())
        {
            Node *node = wave.front().first;
            int level = wave.front().second;
            wave.pop();

            topNodes.insert({level, node->data});

            if (node->left)
            {
                wave.push({node->left, level - 1});
            }

            if (node->right)
            {
                wave.push({node->right, level + 1});
            }
        }

        for (auto kvp : topNodes)
        {
            cout << kvp.second << ' ';
        }
    }
}