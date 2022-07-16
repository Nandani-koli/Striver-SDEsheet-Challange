/*
You are provided with a Binary Tree and one of its leaf nodes. You have to invert this binary tree. Inversion must be done by following all the below guidelines:

• The given leaf node becomes the root after the inversion.

• For a node (say, ‘x’)
    ○ If there exists the left child that is not yet taken then this child must become the right child of ‘x’.
    ○ If the left child is already taken then the right child is still on the right side of ‘x’.

• The parent of ‘x’ must be the left child of ‘x’.

*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool helper(TreeNode<int> *root, TreeNode<int> *leaf, stack<TreeNode<int> *> &st)
{
    st.push(root);
    //     cout<<st.size()<<" ";
    if (!root->left && !root->right)
    {
        if (root->data == leaf->data)
            return true;
        else
        {
            st.pop();
            return false;
        }
    }
    if (root->left)
    {
        if (helper(root->left, leaf, st))
            return true;
    }
    if (root->right)
    {
        if (helper(root->right, leaf, st))
            return true;
    }
    st.pop();
    return false;
}
TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    if (!root)
        return NULL;
    stack<TreeNode<int> *> st;
    bool f = helper(root, leaf, st);
    TreeNode<int> *new_root = st.top();
    st.pop();
    TreeNode<int> *par = new_root;
    while (!st.empty())
    {
        auto cur = st.top();
        st.pop();
        if (cur->left == par)
        {
            cur->left = NULL;
            par->left = cur;
        }
        else
        {
            cur->right = cur->left;
            cur->left = NULL;
            par->left = cur;
        }
        par = cur;
    }
    return new_root;
}
