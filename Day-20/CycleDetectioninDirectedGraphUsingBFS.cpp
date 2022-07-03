/*
You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].
Find whether the graph contains a cycle or not, return true if a cycle is present in the given directed graph else return false.

Cycle Detection in Directed Graph using BFS(Kahn's Algorithm)
*/
#include<iostream>
#include<vector>
#include <queue>
using namespace std;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

    vector<bool> vis(n+1,0);
    vector<int> adj[n+1];
    vector<int> indegree(n+1,0);
    for(int i =0; i<edges.size(); i++)
    {
         adj[edges[i].first].push_back(edges[i].second);
        indegree[edges[i].second]++;
    }
    
 queue<int> q;
    for(int i=1; i<=n; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    int count =0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for(int x: adj[node])
        {
            indegree[x]--;
            if(indegree[x] == 0)
                q.push(x);
        }
    }
    if(count == n) return false;
    
    return true;

}
