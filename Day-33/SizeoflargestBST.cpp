/*
You are given a binary tree with 'N' nodes. Your task is to return the size of the largest subtree of the binary tree which is also a BST.
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


#include<bits/stdc++.h>
vector<int> solve(TreeNode<int> * root)
{
    if(!root) return {1,0,INT_MAX,INT_MIN};
    if(!root->left && !root->right) return {1,1,root->data,root->data};
    
   vector<int> l = solve(root->left);
   vector<int> r = solve(root->right);
    
   if(l[0] && r[0])
   {
       if(root->data > l[3] && root->data < r[2])
       {
       int x = l[2];
       int y = r[3];
       if(x == INT_MAX) x = root->data;
       if(y == INT_MIN) y = root->data;
       return {1,l[1] + r[1] + 1,x,y};
       }
   }
    return {0,max(l[1],r[1]),0,0};  
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    //vector:- {isBST(true/false),size,smallest,largest}
    vector<int> ans = solve(root);
    return ans[1];
}
