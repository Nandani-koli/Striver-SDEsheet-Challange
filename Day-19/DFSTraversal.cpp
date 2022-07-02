/*
Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, the information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.

V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 

E is the number of edges present in graph G.

Note : The Graph may not be connected i.e there may exist multiple components in a graph.


INPUT->
5 4
0 2
0 1
1 2
3 4

OUTPUT->
2               //no. connected component
0 1 2              //1st componenet dfs
3 4                 //2nd component dfs

*/

#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int> &vis,vector<int> adj[],vector<int> &res){
   res.push_back(node);
    vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            dfs(i,vis,adj,res);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int>vis(V,0);
    vector<vector<int>> res;
    vector<int> adj[V+1];
    for(int i = 0;i<E;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(int i = 0;i<V;i++){
        if(!vis[i]){
            vector<int> eachNode;
            dfs(i,vis,adj,eachNode);
            res.push_back(eachNode);
        }
    }
    return res;
}