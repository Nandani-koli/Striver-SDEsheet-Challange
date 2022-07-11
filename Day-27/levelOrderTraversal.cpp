/*
You have been given a Binary Tree of integers. You are supposed to return the level order traversal of the given tree.
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T val;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *newroot = q.front();
        q.pop();

        ans.push_back(newroot->val);
        if (newroot->left)
        {
            q.push(newroot->left);
        }
        if (newroot->right)
        {
            q.push(newroot->right);
        }
    }
    return ans;
}