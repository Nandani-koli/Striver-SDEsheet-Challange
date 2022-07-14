/*
You have been given a binary search tree of integers with ‘N’ nodes. You are also given 'KEY' which represents data of a node of this tree. Your task is to find the predecessor and successor of the given node in the BST.
Note:

1. The predecessor of a node in BST is that node that will be visited just before the given node in the inorder traversal of the tree. If the given node is visited first in the inorder traversal, then its predecessor is NULL.

2. The successor of a node in BST is that node that will be visited immediately after the given node in the inorder traversal of the tree. If the given node is visited last in the inorder traversal, then its successor is NULL.

3. The node for which predecessor and successor are to be found will always be present in the given tree.

4. A binary search tree (BST) is a binary tree data structure which has the following properties.
     • The left subtree of a node contains only nodes with data less than the node’s data.
     • The right subtree of a node contains only nodes with data greater than the node’s data.
     • Both the left and right subtrees must also be binary search trees.
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

     ~BinaryTreeNode()
     {
          if (left)
          {
               delete left;
          }
          if (right)
          {
               delete right;
          }
     }
};

void inorder_predecessor(BinaryTreeNode<int> *root, int &pred, int key)
{
     while (root != NULL)
     {
          if (root->data < key)
          {
               pred = root->data;
               root = root->right;
          }
          else if (root->data >= key)
          {
               root = root->left;
          }
     }
}
void inorder_successor(BinaryTreeNode<int> *root, int &succ, int key)
{
     while (root != NULL)
     {
          if (root->data > key)
          {
               succ = root->data;
               root = root->left;
          }
          else if (root->data <= key)
          {
               root = root->right;
          }
     }
}
pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
     // Write your code here.

     int pred = -1;
     int succ = -1;

     inorder_predecessor(root, pred, key);
     inorder_successor(root, succ, key);

     pair<int, int> ans = {pred, succ};
     return ans;
}
