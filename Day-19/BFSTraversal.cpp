/*
You are given an undirected and disconnected graph G(V, E) having V vertices numbered from 0 to V-1 and E edges. Your task is to print its BFS traversal starting from the 0th vertex.
BFS or Breadth-First Traversal of a graph is an algorithm used to visit all of the nodes of a given graph. In this traversal algorithm, one node is selected, and then all of the adjacent nodes are visited one by one.
An undirected graph is a graph where all the edges are bidirectional, i.e., they point from source to destination and destination to source.
A graph is disconnected if at least two vertices of the graph are not connected by a path.
*/
#include<bits/stdc++.h>
using namespace std;
void bfs(int v, vector<bool> &vis, vector<int> g[],vector<int> &ans)
{
    queue<int> q;
    q.push(v);
    vis[v] = true;
    
    sort(g[v].begin(),g[v].end());
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : g[node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> ans;
     vector<bool> vis(vertex, 0);
    vector<int> adj[vertex];
    
    for(int i = 0; i<edges.size(); i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    
    for (int i = 0; i < vertex; i++)
    {
        if (!vis[i])
        {
           bfs(i,vis,adj,ans);
        }
    }
    
    return ans;
}