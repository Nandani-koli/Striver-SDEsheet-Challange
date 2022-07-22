/*
You are given a 'N' * 'N' maze with a rat placed at 'MAZE[0][0]'. Find and print all paths that rat can follow to reach its destination i.e. 'MAZE['N' - 1]['N' - 1]'. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the 'MAZE' can either be 0 or 1. Cells with value 0 are blocked means the rat can­not enter into those cells and those with value 1 are open.

*/


#include<bits/stdc++.h>
using namespace std;


// Approach 1
void solve(vector<vector<int>> &path, vector<vector<int>> visit, vector<vector<int>> &maze, int n, int row, int col){
    if(row == n-1 && col == n-1){
        vector<int> sub;
        visit[row][col] = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n; j++) {
                sub.push_back(visit[i][j]);
            }
        }
        path.push_back(sub);
        return;
    }
    
    if(col+1<n && !visit[row][col+1] && maze[row][col + 1]){
        visit[row][col] = 1;
        solve(path, visit, maze, n, row, col+1);
        visit[row][col] = 0;
    }
    
    if(row+1<n && !visit[row+1][col] && maze[row + 1][col]){
        visit[row][col] = 1;
        solve(path, visit, maze, n, row+1, col);
        visit[row][col] = 0;
    }
    
    if(row-1>=0 && !visit[row-1][col] && maze[row-1][col]){
        visit[row][col] = 1;
        solve(path, visit, maze, n, row-1, col);
        visit[row][col] = 0;
    }
    
    if(col-1>=0 && !visit[row][col-1] && maze[row][col-1]){
        visit[row][col] = 1;
        solve(path, visit, maze, n, row, col-1);
        visit[row][col] = 0;
    }
    
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> visit(n, vector<int> (n,0));
    vector<vector<int>> path;
    solve(path, visit, maze, n,0,0);
    return path;
    
}


//Approach 2

void dfs(vector<vector<int>> &maze,int i,int j,vector<vector<int>> &vis,int n,vector<vector<int>> &res){
   if(i<0 || j<0 || i>=n || j>=n || maze[i][j]==0 || vis[i][j]==1)   return;
   
   if(i==n-1 && j==n-1 && maze[i][j]==1){
       vector<int> path;
       vis[i][j]=1;
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               path.push_back(vis[i][j]);
           }
       }
       res.push_back(path);
   }
   
   vis[i][j]=1;
   dfs(maze,i+1,j,vis,n,res);    //down
   dfs(maze,i-1,j,vis,n,res);    //up
   dfs(maze,i,j+1,vis,n,res);    //right
   dfs(maze,i,j-1,vis,n,res);    //left
   vis[i][j]=0; 
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> vis(n,vector<int>(n,0));
   vector<vector<int>> res;

   dfs(maze,0,0,vis,n,res);
   return res;
}

