/*
Ninja has been given a postorder and inorder traversal of a Binary Tree of type integer with ‘N’ nodes stored in an array/list ‘POST_ ORDER’ and ‘IN_ORDER’. Ninja has to create the binary tree using the given two arrays/lists and return the root of that tree.
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

TreeNode<int> *BuildTree(vector<int> &postorder, vector<int> &inorder, int ps, int pe, int inS, int inE)
{
    if (ps > pe)
    {
        return NULL;
    }
    int curr = postorder[pe];
    int pos = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (curr == inorder[i])
        {
            pos = i;
            break;
        }
    }

    int lPoS = ps;
    int lInS = inS;
    int lInE = pos - 1;
    int lPoE = lInE - lInS + lPoS;

    int rPoS = lPoE + 1;
    int rInS = pos + 1;
    int rInE = inE;
    int rPoE = pe - 1;
    TreeNode<int> *newnode = new TreeNode<int>(curr);

    newnode->left = BuildTree(postorder, inorder, lPoS, lPoE, lInS, lInE);
    newnode->right = BuildTree(postorder, inorder, rPoS, rPoE, rInS, rInE);

    return newnode;
}
TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inOrder)
{
    // Write your code here.
    int n = inOrder.size() - 1;

    return BuildTree(postOrder, inOrder, 0, n, 0, n);
}
