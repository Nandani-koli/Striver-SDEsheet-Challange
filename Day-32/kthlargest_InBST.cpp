/*
You are given a binary search tree of integers with 'N' nodes. Your task is to return the K-th largest element of this BST.
If there is no K-th largest element in the BST, return -1.
*/
#include<bits/stdc++.h>
using namespace std;
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };


void helper(TreeNode<int>*root,int &k,int &count)
{
    if(root == NULL) return;
    
    helper(root->right,k,count);
    k--;
    if(k == 0) 
    {
        count = root->data;
        return;
    }
     helper(root->left,k,count);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int count=-1;
    helper(root,k,count);
    return count;
}
