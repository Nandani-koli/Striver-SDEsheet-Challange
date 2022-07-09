/*
You have been given a binary tree of integers. You are supposed to find the left view of the binary tree. The left view of a binary tree is the set of all nodes that are visible when the binary tree is viewed from the left side.
*/

#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void recursion(TreeNode<int> *root, int level, vector<int> &res)
{
    if (root == NULL)
        return;
    if (res.size() == level)
        res.push_back(root->data);
    recursion(root->left, level + 1, res);
    recursion(root->right, level + 1, res);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> res;
    recursion(root, 0, res);
    return res;
}