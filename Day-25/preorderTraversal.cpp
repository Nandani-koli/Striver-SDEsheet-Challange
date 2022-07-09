/*
You have been given a Binary Tree of 'N' nodes, where the nodes have integer values. Your task is to find the Pre-Order traversal of the given binary tree.
*/

#include<bits/stdc++.h>
using namespace std;
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

void preorder(TreeNode* root,vector<int> &ans)
{
    //root->left->right
    if(root == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    
    preorder(root,ans);
    
    return ans;
}