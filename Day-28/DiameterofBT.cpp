/*
You are given a Binary Tree. You are supposed to return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two end nodes in a tree.
Note :

The number of edges between two nodes represents the length of the path between them.
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

int getdiameter(TreeNode<int> *root, int &diameter)
{
    if (root == NULL)
        return 0;

    int lh = getdiameter(root->left, diameter);
    int rh = getdiameter(root->right, diameter);

    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    int diameter = 0;
    getdiameter(root, diameter);

    return diameter;
}
