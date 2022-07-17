/*
You have been given a binary tree of integers. You are supposed to serialize and deserialize (refer to notes) the given binary tree. You can choose any algorithm to serialize/deserialize the given binary tree. You only have to ensure that the serialized string can be deserialized to the original binary tree.
Note :

Serialization is the process of translating a data structure or object state into a format that can be stored or transmitted (for example, across a computer network) and reconstructed later. The opposite operation that is, extracting a data structure from stored information, is deserialization.
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


string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    if (root == NULL) return "";
    string str = "";
    queue<TreeNode<int> *> q;
    q.push(root);
    while(!q.empty())
    {
       TreeNode<int> * cur = q.front();
        q.pop();
        
        if(cur == NULL)
        {
            str.append("#,");
        }
        else{
            str.append(to_string(cur->data) + ",");
        }
        
        if(cur != NULL)
        {
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    
    return str;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    if(serialized.size() == 0) return NULL;
    
    stringstream s(serialized);
    string str;
    getline(s,str,',');
    
    TreeNode<int> * root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty())
    {
        TreeNode<int> * node = q.front();
        q.pop();
        
        getline(s,str,',');
        if(str == "#")
        {
            node->left = NULL;
        }
        else{
             TreeNode<int> * leftnode = new TreeNode<int>(stoi(str));
            node->left = leftnode;
            q.push(leftnode);
        }
        
        getline(s,str,',');
        if(str == "#")
        {
            node->right = NULL;
        }
        else{
             TreeNode<int> * rightnode = new TreeNode<int>(stoi(str));
            node->right = rightnode;
            q.push(rightnode);
        }
    }
    
    return root;
}



