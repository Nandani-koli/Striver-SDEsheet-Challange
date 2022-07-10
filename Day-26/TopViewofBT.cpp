/*
You are given a Binary Tree of integers. You are supposed to return the top view of the given binary tree. The Top view of the binary tree is the set of nodes that are visible when we see the tree from the top.

INPUT->
1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

OUTPUT->
8 4 2 1 3 7

Time Complexity: O(N)

Space Complexity: O(N)
*/

#include<bits/stdc++.h>
using namespace std;
    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };


vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
        vector<int> ans;
    if(root == NULL) return ans;
    queue<pair<TreeNode<int> * , int>> q;
    map<int,int> mp;
    q.push({root,0});
    
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        
        TreeNode<int> * node = it.first;
        int line = it.second;
        if(mp.find(line) == mp.end())    mp[line] = node->val;
        
        if(node->left != NULL)
        {
            q.push({node->left,line-1});
        }
        
        if(node->right != NULL)
        {
            q.push({node->right,line+1});
        }
    }
    
    for(auto it : mp)
    {
        ans.push_back(it.second);
    }
    
    return ans;
}