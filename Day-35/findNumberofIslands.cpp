/*
You are given a 2-dimensional array/list having N rows and M columns, which is filled with ones(1) and zeroes(0). 1 signifies land, and 0 signifies water.
A cell is said to be connected to another cell, if one cell lies immediately next to the other cell, in any of the eight directions (two vertical, two horizontal, and four diagonals).
A group of connected cells having value 1 is called an island. Your task is to find the number of such islands present in the matrix.
*/
#include<iostream>
using namespace std;

bool isvalid(int i, int j,int n,int m,int** &arr)
{
    if(i >= 0 && i<n && j >= 0 && j < m && arr[i][j] == 1)
        return true;
    
    return false;
}
void dfs(int i, int j,int n,int m,int** &arr)
{
    arr[i][j] = 0;
    
    if(isvalid(i-1,j,n,m,arr))              //up
        dfs(i-1,j,n,m,arr);
    
    if(isvalid(i+1,j,n,m,arr))             //down
        dfs(i+1,j,n,m,arr);
    
    if(isvalid(i,j+1,n,m,arr))              //right
        dfs(i,j+1,n,m,arr);
    
    if(isvalid(i,j-1,n,m,arr))              //left
        dfs(i,j-1,n,m,arr);
    
    if(isvalid(i-1,j+1,n,m,arr))            //up-right
        dfs(i-1,j+1,n,m,arr);
    
    if(isvalid(i+1,j+1,n,m,arr))            //down-right
        dfs(i+1,j+1,n,m,arr);
    
    if(isvalid(i-1,j-1,n,m,arr))            //up-left
        dfs(i-1,j-1,n,m,arr);
    
    if(isvalid(i+1,j-1,n,m,arr))            //down-left
        dfs(i+1,j-1,n,m,arr);
    
}
int getTotalIslands(int** arr, int n, int m)
{
    int ans = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(arr[i][j] == 1)
            {
                ans++;
                dfs(i,j,n,m,arr);
            }
        }
    }
    
    return ans;
}
