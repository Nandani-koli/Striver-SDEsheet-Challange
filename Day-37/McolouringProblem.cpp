/*
You are given an undirected graph in the form of an adjacency matrix along with an integer M. You need to tell if you can color the vertices of the graph using at most M colors such that no two adjacent vertices are of the same color.
For example:

If the given adjacency matrix is:
[0 1 0]
[1 0 1]
[0 1 0] and M = 3.
The given adjacency matrix tells us that 1 is connected to 2 and 2 is connected to 3. So if we color vertex 1 with 2, vertex 2 with 1, and vertex 3 with 2, it is possible to color the given graph with 2 colors: M.

*/
#include<iostream>
#include<vector>
using namespace std;

bool isPossible(int node,vector<int>&color,
                int n,vector<vector<int>>&mat,int col)
{
    for(int k=0;k<n;k++){
        if(k!=node && mat[node][k]==1 && color[k]==col){
            return false;
        }
    }
    return true;
}
bool solve(int node,vector<int>&color,vector<vector<int>>&mat,int n,int m){
    
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isPossible(node,color,n,mat,i)){
            color[node]=i;
            if(solve(node+1,color,mat,n,m)){
                return true;
            }
            color[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n=mat.size();
    vector<int>color(n,0);
    if(solve(0,color,mat,n,m)){
        return "YES";
    }
    return "NO";
}