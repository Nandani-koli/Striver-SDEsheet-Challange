/*
Given a binary tree with N number of nodes, check if that input tree is Partial BST (Binary Search Tree) or not. If yes, return true, return false otherwise.
A binary search tree (BST) is said to be a Partial BST if it follows the following properties.

• The left subtree of a node contains only nodes with data less than and equal to the node’s data.
• The right subtree of a node contains only nodes with data greater than and equal to the node’s data.
• Both the left and right subtrees must also be partial binary search trees.
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


//brute force tc->O(n) sc-> O(n)
void inorder(BinaryTreeNode<int> *root, vector<int> &v)
{
    if (root)
    {
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
}
bool validateBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    vector<int> v;
    inorder(root, v);
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < v[i - 1])
        {
            return false;
        }
    }
    return true;
}

//better approach recursive TC:- O(n) SC:- O(1)
#include<bits/stdc++.h>
 bool isValidBST(BinaryTreeNode<int> *root, int minVal, int maxVal) {
        if (root == NULL) return true;
        if (root->data > maxVal || root->data < minVal) return false;
        return isValidBST(root->left, minVal, root->data) && isValidBST(root->right, root->data, maxVal);
    }
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    int minvalue = INT_MIN;
    int maxvalue = INT_MAX;
    return isValidBST(root, minvalue,maxvalue);

}