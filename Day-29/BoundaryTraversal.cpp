/*
You have been given a binary tree of integers. Your task is to print the boundary nodes of this binary tree in Anti-Clockwise direction starting from the root node.
NOTE:

The boundary nodes of a binary tree include nodes from the left boundary, right boundary and the leaf nodes without duplicate nodes. However, the values from the nodes may contain duplicates.
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

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool isleaf(TreeNode<int> *node)
{
    return !node->left && !node->right;
}

void addrightboundary(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *cur = root->right;
    stack<int> st;
    while (cur)
    {
        if (!isleaf(cur))
            st.push(cur->data);

        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}

void addleftboundary(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *cur = root->left;
    while (cur)
    {
        if (!isleaf(cur))
            ans.push_back(cur->data);

        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void addleaf(TreeNode<int> *root, vector<int> &ans)
{
    if (isleaf(root))
    {
        ans.push_back(root->data);
        return;
    }

    if (root->left)
        addleaf(root->left, ans);
    if (root->right)
        addleaf(root->right, ans);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (!root)
        return ans;

    if (!isleaf(root))
        ans.push_back(root->data);

    addleftboundary(root, ans);
    addleaf(root, ans);
    addrightboundary(root, ans);

    return ans;
}