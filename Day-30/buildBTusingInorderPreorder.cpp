/*
You have been given the preorder and inorder traversal of a binary tree. Your task is to construct a binary tree using the given inorder and preorder traversals.
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

TreeNode<int> *BuildTree(vector<int> &inorder, vector<int> &preorder, int inS, int inE, int preS, int preE)
{
    if (inS > inE) // base condition
    {
        return NULL;
    }

    int curr = preorder[preS]; // 1. pick 1st element from preorder
    int pos = -1;              // search for picked element
    for (int i = inS; i <= inE; i++)
    {
        if (inorder[i] == curr)
        {
            pos = i;
            break;
        }
    }

    TreeNode<int> *newnode = new TreeNode<int>(curr);

    int lps = preS + 1;
    int lpe = (pos - 1) - inS + lps;
    int rps = lpe + 1;
    int rpe = preE;

    newnode->left = BuildTree(inorder, preorder, inS, pos - 1, lps, lpe);  // 4. call to build leftsubtree
    newnode->right = BuildTree(inorder, preorder, pos + 1, inE, rps, rpe); // 5. call to build rightsubtree

    return newnode;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    //    Write your code here

    return BuildTree(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
}