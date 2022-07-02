/*
You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.
Your task is to find if the graph contains a cycle or not.
A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.

using BFS Algo
*/
#include<bits/stdc++.h>
using namespace std;
bool iscycle(int s,vector<bool> &vis,vector<int> g[])
{
    queue<pair<int,int>> q;
    q.push({s,-1});
    vis[s] = 1;

    while (!q.empty())
    {
        int node = q.front().first;
        int prev = q.front().second;
        q.pop();
        for(auto it : g[node])
        {
            if(!vis[it])
            {
                q.push({it,node});
                vis[it] = 1;
            }
            else if(prev != it) 
                return true;
        }
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
           if(iscycle(i,vis,adj)) return "Yes";
        }
    }
    return "No";
}
