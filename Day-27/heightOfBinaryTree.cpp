/*
You have been given the Inorder Traversal and Level Order Traversal of a Binary Tree of integers. Your task is to calculate the height of the Binary tree without constructing it.
The height of the binary tree is the number of edges in the longest path from the root node to any leaf node in the tree. In case the tree has only one node, the height is taken to be 0.
*/

#include<bits/stdc++.h>
using namespace std;
// Approach 1
int search(vector<int> arr, int strt, int end, int value)
{
    for (int i = strt; i <= end; i++)
        if (arr[i] == value)
            return i;
    return -1;
}

int getheight(vector<int> inorder, vector<int> levelOrder, int start,int end, int &height, int n)
{
    if(start > end)
        return 0;
    
    int getindex = search(inorder, start, end, levelOrder[0]);
    
    if(getindex == -1)
        return 0;
    
    int leftcount = getindex - start;
    int rightcount = end - getindex;
    
    vector<int> newleftlevel(leftcount);
    vector<int> newrightlevel(rightcount);
    
    int leftht = 0, rightht = 0;
    int k = 0;
    
    for(int i = 0; i< n; i++)
    {
        for(int j = start; j < getindex; j++)
        {
            if(levelOrder[i] == inorder[j])
            {
            newleftlevel[k] = levelOrder[i];
            k++;
            break;
            }
        }
    }
    
    k = 0;
     for(int i = 0; i< n; i++)
    {
        for(int j = getindex + 1; j <= end ; j++)
        {
            if(levelOrder[i] == inorder[j])
            {
            newrightlevel[k] = levelOrder[i];
            k++;
            break;
            }
        }
    }
    
    //recursive call
    if(leftcount > 0)
    {
        leftht = getheight(inorder,newleftlevel,start,getindex-1,height,leftcount);
    }
    
     if(rightcount > 0)
    {
        rightht = getheight(inorder,newrightlevel,getindex+1,end,height,rightcount);
    }
    
    height = max(leftht+1, rightht+1);
    
    newleftlevel.clear();
    newrightlevel.clear();
    
    return height;
    
}
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	// Write your code here.
    int height = 0;
    getheight(inorder,levelOrder,0,N-1,height,N);
    
    return height-1;
}


//Approach 2

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){

    unordered_map<int, int> mp; // Inorder Node value -> index in inorder array
    queue<vector<int>> q; // {start, end, height}
    
    for(int i = 0; i < inorder.size(); i++){
        mp[inorder[i]] = i;
    }
    
    if(mp.find(levelOrder[0]) != mp.end()){
        // root is the last element in inorder traversal then it has no right subtree
        if(mp[levelOrder[0]] == inorder.size()-1) 
            q.push({0, (int)inorder.size()-2, 1});
        // root is the first element in inorder traversal then it has no left subtree
        else if(mp[levelOrder[0]] == 0)
            q.push({1, (int)inorder.size()-1, 1});
        else
        {
            q.push({0, mp[levelOrder[0]]-1, 1});    // left subtree
            q.push({mp[levelOrder[0]]+1, (int)inorder.size()-1, 1});    // right subtree
        }
    }
    int k = 1;
    int ans = 0;
   while(!q.empty())
   {  
    auto temp = q.front();
    q.pop();
    ans = max(ans, temp[2]);
    if(mp.find(levelOrder[k]) != mp.end()){  
        // if it is the leaf node i.e. no left subtree and no right subtree 
        if(temp[0] == temp[1]) 
            ans = max(ans, temp[2] + 1);
        // root is the last element in inorder traversal then it has no right subtree
        else if(mp[levelOrder[k]] == temp[1])
            q.push({temp[0], temp[1]-1, temp[2]+1});
        // root is the first element in inorder traversal then it has no left subtree
        else if(mp[levelOrder[k]] == temp[0])
            q.push({temp[0]+1, temp[1], temp[2]+1});
        else
        {
            q.push({temp[0], mp[levelOrder[k]]-1, temp[2]+1}); // left subtree
            q.push({mp[levelOrder[k]]+1, temp[1], temp[2]+1});    // right subtree
        }
    }
    k++;
   }
   return ans-1;
}
