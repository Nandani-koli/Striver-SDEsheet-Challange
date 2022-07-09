/*
You have been given a Binary Tree of 'N' nodes, where the nodes have integer values. Your task is to find the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.

find preorder,inorder and postorder in single traverse 
TC:- O(n)
Sc-> O(n)
*/

#include <bits/stdc++.h>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode*right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> getTreeTraversal(BinaryTreeNode *root)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> pre, in, post;
    if (root == NULL)
        return ans;
    stack<pair<BinaryTreeNode*, int>> s;
    s.push({root, 1});
    while (!s.empty())
    {
        auto p = s.top();
        s.pop();
        if (p.second == 1)
        {
            pre.push_back(p.first->data);
            p.second++;
            s.push(p);
            if (p.first->left)
                s.push({p.first->left, 1});
        }
        else if (p.second == 2)
        {
            in.push_back(p.first->data);
            p.second++;
            s.push(p);
            if (p.first->right)
                s.push({p.first->right, 1});
        }
        else if (p.second == 3)
        {
            post.push_back(p.first->data);
        }
    }
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}
