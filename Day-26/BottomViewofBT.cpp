/*
Given a binary tree, print its bottom view from left to right. Assume, the left and the right child make a 45-degree angle with the parent.
A binary tree is a tree in which each parent node has at most two children.
A node will be in the bottom-view if it is the bottom-most node at its horizontal distance from the root.

Note :

1. The horizontal distance of the root from itself is 0. The horizontal distance of the right child of the root node is 1 and the horizontal distance of the left child of the root node is -1.

2. The horizontal distance of node 'n' from root = horizontal distance of its parent from root + 1, if node 'n' is the right child of its parent.

3. The horizontal distance of node 'n' from root = horizontal distance of its parent from the root - 1, if node 'n' is the left child of its parent.

4. If more than one node is at the same horizontal distance and is the bottom-most node for that horizontal distance, including the one which is more towards the right.

INPUT->
1 2 3 -1 -1 5 6 7 8 -1 -1 -1 -1 -1 -1

OUTPUT->
7 5 8 6

TC:- O(n)
SC:- O(n)
*/

#include <bits/stdc++.h>
using namespace std;
template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> bottomView(BinaryTreeNode<int> *root)
{

    // Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    map<int, int> mp;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        BinaryTreeNode<int> *node = it.first;
        int line = it.second;
        mp[line] = node->data;

        if (node->left != NULL)
        {
            q.push({node->left, line - 1});
        }

        if (node->right != NULL)
        {
            q.push({node->right, line + 1});
        }
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}
