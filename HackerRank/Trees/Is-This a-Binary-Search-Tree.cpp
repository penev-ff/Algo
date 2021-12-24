/**
 * 
 *  Author: Ivan Penev
 *  Source: https://www.hackerrank.com/challenges/is-binary-search-tree/
 *  Time: O(n)
 *  Space: O(h)
 *
*/

#include <vector>

using namespace std;

// The Node struct is defined as follows:
struct Node
{
    double data;
    Node *left;
    Node *right;

    Node(double data, Node *left = nullptr, Node *right = nullptr)
        : data(data), left(left), right(right) {}
};

// Solution 1:
bool checkBSTRec(Node *root, Node *min, Node *max)
{
    if (!root)
    {
        return true;
    }

    if ((!min || root->data > min->data) && (!max || root->data < max->data))
    {
        return checkBSTRec(root->left, min, root) && checkBSTRec(root->right, root, max);
    }

    return false;
}

bool checkBST_v2(Node *root)
{
    return checkBSTRec(root, nullptr, nullptr);
}

// Solution 2:
void inorder(Node *root, vector<int> &v)
{
    if (root)
    {
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
}

bool isSortedIncr(vector<int> &v)
{
    if (v.empty())
    {
        return true;
    }

    for (size_t i = 0; i < v.size() - 1; i++)
    {
        if (v[i] >= v[i + 1])
        {
            return false;
        }
    }

    return true;
}

bool checkBST(Node *root)
{
    if (!root)
    {
        return true;
    }

    vector<int> vInorder;
    inorder(root, vInorder);

    return isSortedIncr(vInorder);
}
