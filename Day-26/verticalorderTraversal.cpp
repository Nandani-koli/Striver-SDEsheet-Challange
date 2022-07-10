/*
Given a binary tree, return the vertical order traversal of the values of the nodes of the given tree.
For each node at position (X, Y), (X-1, Y-1) will be its left child position while (X+1, Y-1) will be the right child position.
Running a vertical line from X = -infinity to X = +infinity, now whenever this vertical line touches some nodes, we need to add those values of the nodes in order starting from top to bottom with the decreasing ‘Y’ coordinates.
Note:

If two nodes have the same position, then the value of the node that is added first will be the value that is on the left side.

*/

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

#include <bits/stdc++.h>
using namespace std;
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ans;
    map<int, map<int, vector<int>>> nodes;
    queue<pair<TreeNode<int> *, pair<int, int>>> q;
    if (root == NULL)
        return ans;
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<TreeNode<int> *, pair<int, int>> temp = q.front();
        q.pop();
        TreeNode<int> *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        nodes[hd][lvl].push_back(frontNode->data);
        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    return ans;
}