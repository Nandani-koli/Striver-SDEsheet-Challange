/*
Given a Binary Tree, convert this binary tree to a Doubly Linked List.
A Binary Tree (BT) is a data structure in which each node has at most two children.
A Doubly Linked List contains a previous pointer, along with the next pointer and data.
The order of nodes in Doubly Linked List must be the same as Inorder of the given Binary Tree.
The doubly linked list should be returned by taking the next pointer as right and the previous pointer as left.
You need to return the head of the Doubly Linked List.
*/

#include<bits/stdc++.h>
using namespace std;
template<typename T>

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

queue<int> q;
void inorder(BinaryTreeNode<int>* root){
    if(root){
        inorder(root->left);
        q.push(root->data);
        inorder(root->right);
    }
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    if(!root)return NULL;
    inorder(root);
    BinaryTreeNode<int>* cur=new BinaryTreeNode<int>(q.front());
    root=cur;
    q.pop();

    while(!q.empty()){
        cur->left=NULL;
        cur->right=new BinaryTreeNode<int>(q.front());
        cur=cur->right;
        q.pop();
    }
    return root;
}
