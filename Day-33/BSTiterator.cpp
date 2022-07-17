/*
You are given a class named as BSTIterator that represents an iterator over inorder traversal of a binary search tree. You need to implement the following things as follows:

1. BSTIterator(Node root) - It is a parameterized constructor in which you are given the root of the Binary search tree. It will be called whenever an object of BSTIterator is created.

2. next() - This member function will return the next smallest element in the in-order traversal of the binary search tree. You need to implement this function.

3. hasNext() - This function will return true if there exists the next smallest element in the traversal else it will return false. You need to implement this function

The binary search tree has ‘N’ nodes you need to print the inorder traversal of the tree using the iterator.
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

#include<bits/stdc++.h>
class BSTiterator
{
    stack<TreeNode<int> *> st;
    void pushall(TreeNode<int> * node)
    {
        for(; node != NULL; st.push(node), node = node->left);
    }
    public :
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushall(root);
        
    }

    int next()
    {
        // write your code here
        TreeNode<int> * temp = st.top();
        st.pop();
        pushall(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        // write your code here
        return !st.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/