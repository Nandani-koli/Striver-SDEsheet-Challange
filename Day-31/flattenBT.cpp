/*
You are given a binary tree consisting of integer values. Your task is to convert the given binary tree into a linked list where the nodes of the linked list follow the same order as the pre-order traversal of the given binary tree.
Note:

Use the right pointer of the binary tree as the “next” pointer for the linked list and set the left pointer to NULL. 
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


//solution 1 Recursively TC-> O(n)  SC-> O(n)
TreeNode<int>* p =NULL; 
void flatten(TreeNode<int>*root)
{   
    if(!root) return ;
   flatten(root->right);
   flatten(root->left);

   root->right = p;
   root->left = NULL;
   p = root; 
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)

{
    p = NULL;
   flatten(root);
   return root; 
}


//solution -2 ITERATIVE TC-> O(n) SC-> O(n)

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    stack<TreeNode<int>* > st;
    st.push(root);
    while(!st.empty())
    {
        TreeNode<int> * cur = st.top();
        st.pop();
        
        if(cur->right) st.push(cur->right);
        if(cur->left) st.push(cur->left);
        
        if(!st.empty())
            cur->right = st.top();
        
        cur->left = NULL;
    }
    
    return root;
}


//Optimized solution using morris preorder traversal
//TC->O(n) SC->O(n)

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int> *cur = root;
    while(cur)
    {
        if(cur->left)
        {
            TreeNode<int> *prev = cur->left;
            while(prev->right)
            {
                prev = prev->right;
            }
            prev->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
    
    return root;
}