/*
There is a Binary Search Tree (BST) consisting of ‘N’ nodes. Each node of this BST has some integer data.
You are given a pointer to the root node of this BST, and an integer ‘X’. Print "True" if there is a node in BST having data equals to ‘X’, otherwise print "False".
A binary search tree (BST) is a binary tree data structure that has the following properties.

1. The left subtree of a node contains only nodes with data less than the node’s data.
2. The right subtree of a node contains only nodes with data greater than the node’s data.
3. Both the left and right subtrees must also be binary search trees.

*/

#include<bits/stdc++.h>
using namespace std;

template<typename T>

    class BinaryTreeNode {
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


bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root == NULL)
    {
        return false;
    }
    
    if(x < root->data)
    {
        return searchInBST(root->left,x);
    }
    else if(x > root->data)
    {
       // key > root->data
        return searchInBST(root->right,x);
    }
    return true;
}