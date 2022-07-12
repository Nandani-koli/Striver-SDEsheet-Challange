/*
You have been given a Binary Tree of distinct integers and two nodes ‘X’ and ‘Y’. You are supposed to return the LCA (Lowest Common Ancestor) of ‘X’ and ‘Y’.
The LCA of ‘X’ and ‘Y’ in the binary tree is the shared ancestor of ‘X’ and ‘Y’ that is located farthest from the root.
Note :

You may assume that given ‘X’ and ‘Y’ definitely exist in the given binary tree.

INPUT_>
1 2 3 4 7 -1 -1 -1 -1 -1 -1
4 7

OUTPUT->
2

*/
#include <iostream>
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

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    //    Write your code here
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == x || root->data == y)
    {
        return root->data;
    }

    int left = lowestCommonAncestor(root->left, x, y);
    int right = lowestCommonAncestor(root->right, x, y);

    if (left == -1)
        return right;
    else if (right == -1)
        return left;
    else
        return root->data;
}