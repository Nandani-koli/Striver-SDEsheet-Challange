/*
You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].
Find whether the graph contains a cycle or not, return true if a cycle is present in the given directed graph else return false.
*/
#include<bits/stdc++.h>
using namespace std;
bool iscycle(int node, vector<bool>&vis, vector<bool> &dfstrack, vector<int> g[])
{
    vis[node] = 1;
    dfstrack[node] = 1;
    for(auto it : g[node])
    {
        if(!vis[it])
        {
        if(iscycle(it,vis,dfstrack,g)) return true;
        }else if(dfstrack[it]) return true;
    }
    dfstrack[node] = 0;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    
    vector<bool> vis(n+1,0);
    vector<bool> dfstrack(n+1,0);
    vector<int> adj[n+1];
    
    for(int i = 0; i<edges.size(); i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    
    for(int i = 1; i<= n; i++)
    {
        if(!vis[i])
        {
            if(iscycle(i,vis,dfstrack,adj)) return 1;
        }
    }
    return 0;
}