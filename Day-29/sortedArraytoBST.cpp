/*
You have been given a sorted array of length ‘N’. You need to construct a balanced binary search tree from the array. If there can be more than one possible tree, then you can return any.
Note:

1. A balanced binary tree is a binary tree structure in which the left and right subtrees of every node differ in height by no more than 1.

2. A binary search tree is a binary tree data structure, with the following properties
    a. The left subtree of any node contains nodes with value less than the node’s value.
    b. The right subtree of any node contains nodes with values equal to or greater than the node’s value.
    c. Right, and left subtrees are also binary search trees.

*/

#include <bits/stdc++.h>
using namespace std;
    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

TreeNode<int>* sortedArrayToBST(vector<int> &arr, int st, int end)
{
    // Write your code here.
     if(st > end)
    {
        return NULL;
    }
    int mid = (st + end)/2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);

    root->left = sortedArrayToBST(arr,st,mid-1);
    root->right = sortedArrayToBST(arr,mid+1,end);

    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
   return sortedArrayToBST(arr,0,n-1);
}