/*
Preorder Traversal of Binary Tree in TC-> O(n) and Sc-> O(1)
using threaded Binary tree concept
*/
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> preorder;
    TreeNode *cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            preorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            TreeNode *prev = cur->left;
            while (prev->right && prev->right != cur)
            {
                prev = prev->right;
            }

            if (prev->right == NULL)
            {
                prev->right = cur;
                preorder.push_back(cur->data);
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }

    return preorder;
}