/*
You are given a non-empty binary tree where each node has a non-negative integer value. Return the maximum possible sum of path between any two leaves of the given tree.
The path is also inclusive of the leaf nodes and the maximum path sum may or may not go through the root of the given tree.
If there is only one leaf node in the tree, then return -1.
*/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };



long long int maxsumpath(TreeNode<int> *root, lli &maxii)
{
    if(root == NULL) return 0;
    
    lli leftmax = maxsumpath(root->left, maxii);
    lli rightmax = maxsumpath(root->right, maxii);
    
    maxii = max(maxii, root->val + leftmax + rightmax);
    
    return root->val + max(leftmax,rightmax);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(!root) return -1;
    if(!root->left || !root->right)  return -1;
    
    lli maxii = INT_MIN;
    maxsumpath(root,maxii);
    
    return maxii;
}