/**
 * 
 *  Author: Ivan Penev
 *  Source: https://www.hackerrank.com/challenges/tree-level-order-traversal/
 *  Time: O(n)
 *  Space: O(h)
 *
*/

#include <iostream>
#include <queue>

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

void levelOrder(Node *root)
{
    if (root)
    {
        queue<Node *> wave;
        wave.push(root);

        while (!wave.empty())
        {

            Node *toProcess = wave.front();
            wave.pop();

            cout << toProcess->data << ' ';

            if (toProcess->left)
            {
                wave.push(toProcess->left);
            }

            if (toProcess->right)
            {
                wave.push(toProcess->right);
            }
        }
    }
}