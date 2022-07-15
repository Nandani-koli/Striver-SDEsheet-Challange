/*
You are given a preorder traversal of a binary search tree, your task is to find the tree from the given preorder traversal.
*/


#include<bits/stdc++.h>
using namespace std;
    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };



//optimized Approach TC:- O(n) SC:- recursion stack O(n)
TreeNode<int>* buildTree(vector<int> &preOrder, int &i, int bound)
{
    if(i == preOrder.size() || preOrder[i] > bound ) return NULL;
    
    TreeNode<int>* root = new TreeNode<int>(preOrder[i++]);
    root->left = buildTree(preOrder,i,root->data);
    root->right = buildTree(preOrder,i,bound);
    
    return root;
    
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i = 0;
    int bound = INT_MAX;
    return buildTree(preOrder,i,bound);
}


//approach 2 taking extra space 

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    if(preOrder.size()==0) return NULL;
    TreeNode<int>* node=new TreeNode<int>(preOrder[0]);
    vector<int> lessThan;
    vector<int> greaterThan;
    for(int i=1; i<preOrder.size(); i++)
    {
        if(preOrder[i]<preOrder[0]) lessThan.push_back(preOrder[i]);
        else greaterThan.push_back(preOrder[i]);
    }
    node->left=preOrderTree(lessThan);
    node->right=preOrderTree(greaterThan);
    return node;
}