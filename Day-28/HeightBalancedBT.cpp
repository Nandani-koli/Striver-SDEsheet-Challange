/*
Given a binary tree. You need to check if it is a height-balanced binary tree.
Height of a tree is the maximum number of nodes in a path from the node to the leaf node.
An empty tree is a height-balanced tree. A non-empty binary tree is a height-balanced binary tree if
1. The left subtree of a binary tree is already the height-balanced tree.
2. The right subtree of a binary tree is also the height-balanced tree.
3. The difference between heights of left subtree and right subtree must not more than ‘1’.
*/

#include<bits/stdc++.h>
using namespace std;
template <typename T>
    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

bool isBalanced(BinaryTreeNode<int>* root, int *height)         //time complexity = O(n)
{   
    if(root == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;
    if(isBalanced(root->left, &lh) == false)
    {
        return false;
    }
    if(isBalanced(root->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh,rh)+1;
    if(abs(lh-rh) <= 1)
    {
        return true;
    }
    else{
        return false;
    }

}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
     int height = 0;
     return isBalanced(root,&height);
}