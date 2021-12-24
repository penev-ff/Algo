/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 *  Time: O() 
 *  Space: O()
 *
*/

#include <queue>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;

        queue<Node *> wave;
        wave.push(root);

        while (!wave.empty())
        {
            int toProcess = wave.size();
            Node *prev = nullptr;

            for (int i = 0; i < toProcess; i++)
            {
                Node *front = wave.front();
                wave.pop();

                if (front->left)
                    wave.push(front->left);

                if (front->right)
                    wave.push(front->right);

                if (!prev)
                {
                    prev = front;
                    continue;
                }

                prev->next = front;
                prev = front;
            }
        }

        return root;
    }
};

int main()
{

    Solution sol;

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    sol.connect(root);

    return 0;
}