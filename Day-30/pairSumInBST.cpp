/*
You are given a Binary Search Tree (BST) and a target value ‘K’. Your task is to check if there exist two unique elements in the given BST such that their sum is equal to the given target ‘K’.
*/

#include<bits/stdc++.h>
using namespace std;

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };


void inorder(BinaryTreeNode<int>* root, vector<int> &v)
{
    if(root)
    {
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
     if(root==NULL) return false;
    vector<int> v;
    inorder(root, v);
    int i=0, j=v.size()-1;
    while(i<j)
    {
        if(v[i]+v[j]==k) return true;
        else if(v[i]+v[j]>k) j--;
        else i++;
    }
    return false;
}
