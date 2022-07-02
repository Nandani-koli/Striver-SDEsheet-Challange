/*
You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.
Your task is to find if the graph contains a cycle or not.
A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.

*/
#include<bits/stdc++.h>
using namespace std;
bool iscycle(int node, int prev, vector<bool>&vis, vector<int> adj[])
{
    vis[node] = 1;
    for(auto it : adj[node])
    {
        if(!vis[it])
        {
        if(iscycle(it,node,vis,adj)) return true;
        }
        else if(it != prev) return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n+1];
    vector<bool> vis(n+1,0);
    for(int i = 0;i<m;i++){

        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(int i =1; i<=n; i++)
    {
        if (!vis[i])
        {
           if(iscycle(i,-1,vis,adj)) return "Yes";
        }
    }
    return "No";
}
