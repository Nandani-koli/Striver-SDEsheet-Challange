/*
You are given a binary tree with ‘N’ number of nodes and a node ‘X’. Your task is to print the path from the root node to the given node ‘X’.
A binary tree is a hierarchical data structure in which each node has at most two children.

INPUT->
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
7

OUTPUT->
1 3 7 

*/

#include <iostream>
#include <vector>
using namespace std;

template <typename T = int>
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

bool getpath(TreeNode<int> *root, vector<int> &ans, int x)
{
	if (root == NULL)
		return false;

	ans.push_back(root->data);

	if (root->data == x)
		return true;

	if (getpath(root->left, ans, x) || getpath(root->right, ans, x))
		return true;

	ans.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
	vector<int> ans;
	if (!root)
		return ans;

	getpath(root, ans, x);

	return ans;
}
