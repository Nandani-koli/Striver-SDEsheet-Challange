/*
Given a binary tree of nodes 'N', you need to modify the value of its nodes, such that the tree holds the Children sum property.
A binary tree is said to follow the children sum property if, for every node of that tree, the value of that node is equal to the sum of the value(s) of all of its children nodes( left child and the right child).
Note :

 1. You can only increment the value of the nodes, in other words, the modified value must be at least equal to the original value of that node.
 2. You can not change the structure of the original binary tree.
 3. A binary tree is a tree in which each node has at most two children.
 4. You can assume the value can be 0 for a NULL node and there can also be an empty tree.
*/

#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void changeTree(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return;
    int childsum = 0;
    if (root->left)
        childsum += root->left->data;
    if (root->right)
        childsum += root->right->data;

    if (childsum >= root->data)
        root->data = childsum;
    else
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int update = 0;
    if (root->left)
        update += root->left->data;
    if (root->right)
        update += root->right->data;

    if (root->left || root->right)
        root->data = update;
}