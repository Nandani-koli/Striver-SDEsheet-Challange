/*
You have been given a Binary Tree of integers. You are supposed to return the maximum width of the given Binary Tree. The maximum width of the tree is the maximum width among all the levels of the given tree.
The width of one level is defined as the length between the leftmost and the rightmost, non-null nodes in the level, where the null nodes in between the leftmost and rightmost are excluded into length calculation.

Sample Input :

2 7 5 2 6 -1 9 -1 -1 5 11 4 -1 -1 -1 -1 -1 -1 -1

Sample Output :

3

Explanation of Sample Input :

The maximum width will be at the third level i.e. {2, 6, 9} and the fourth level with the length of 3, i.e. {5, 11, 4}. So the maximum width will be 3.

*/

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


#include<bits/stdc++.h>
using namespace std;
int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    
    int maxcount=1;
    if(root==NULL)return 0;
    queue<TreeNode<int>*> helper;
    helper.push(root);
    while(!helper.empty()){
        int tempcount=0;
        int s=helper.size();
        for(int i=0;i<s;i++){
            if(helper.front()->left!=NULL){
                tempcount++;
                helper.push(helper.front()->left);
            }
            if(helper.front()->right!=NULL){
                tempcount++;
                helper.push(helper.front()->right);
            }
            helper.pop();
        }
        maxcount=max(maxcount,tempcount);
    }
    return maxcount;
}