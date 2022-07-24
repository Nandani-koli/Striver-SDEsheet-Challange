/*
You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i] [j], you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].
*/

//solution-1 
#include <bits/stdc++.h> 
using namespace std;
 int countPaths(int i,int j,int n,int m,vector<vector<int>> &dp)
    {
        if(i==(n-1)&&j==(m-1)) return 1;
        if(i>=n||j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
     else return dp[i][j]=countPaths(i+1,j,n,m,dp)+countPaths(i,j+1,n,m,dp);
        
    }
int uniquePaths(int m, int n) {
	// Write your code here.
     vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
       
        //dp[1][1]=1;
       int num=countPaths(0,0,m,n,dp);
        if(m==1&&n==1)
            return num;
        return dp[0][0];
}

//solution-2 tc:- O(n-1) sc-> O(1)

int uniquePaths(int m, int n) {
	// Write your code here.
    int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
}
