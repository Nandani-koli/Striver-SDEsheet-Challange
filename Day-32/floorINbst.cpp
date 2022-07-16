/*
You are given a BST (Binary search tree) with’ N’ number of nodes and a value ‘X’. Your task is to find the greatest value node of the BST which is smaller than or equal to ‘X’.
Note :‘X’ is not smaller than the smallest node of BST .
*/
#include<bits/stdc++.h>
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


int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
  int floor = 0;
   while(root != NULL)
   {
       if(root->val == X)
       {
           floor = root->val;
           return floor;
       }
       else if( root->val > X)
       {
           root = root->left;
       }
       else{
           floor = root->val;
           root = root->right;
       }
   }
    return floor;
}