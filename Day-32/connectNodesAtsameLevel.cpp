/*
A binary tree is a tree where each node has at most two children i.e left child and right child.
You are given a binary tree, where the structure of the node is as follow -:

class BinaryTreeNode {
 int data;      // Value of the node.
 BinaryTreeNode *left;  // Pointer to left child node.
 BinaryTreeNode *right; // Pointer to right child node.
 BinaryTreeNode *next;  // Pointer to next right node at same level. 
}

Your task is to connect all the adjacent nodes at the same level in the given binary tree. You can do this by populating each 'next' pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL. Initially, all the next pointers are set to NULL.
*/

//Approach 1 using level order traversal and queue TC:- O(n) Sc:- O(n)
#include<bits/stdc++.h>
using namespace std;
    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };


void connectNodes(BinaryTreeNode< int > *root) {
    queue <BinaryTreeNode< int > *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        BinaryTreeNode< int > *node = q.front();
        q.pop();
        
        if(node != NULL)
        {
        node->next = q.front();
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
        }
    }
}