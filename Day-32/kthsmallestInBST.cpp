/*
You have been given a Binary Search Tree of integers. You are supposed to return the k-th (1-indexed) smallest element in the tree.
*/
#include<bits/stdc++.h>
using namespace std;

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

void helper(TreeNode<int>*root,int &k,int &count)
{
    if(root == NULL) return;
    helper(root->left,k,count);
    k--;
    if(k == 0) 
    {
        count = root->data;
        return;
    }
    helper(root->right,k,count);
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
     int count=0;
    helper(root,k,count);
    return count;
}