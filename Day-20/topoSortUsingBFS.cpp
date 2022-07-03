/*
A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.
Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG. Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.

kahn's Algorithm
*/
#include<vector>
#include <queue>
#include<iostream>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
   vector<int> ans;
    vector<int> adj[v];
    vector<int> indegree(v,0);
                         
    for(int i = 0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        
        indegree[edges[i][1]]++;
    }
    
    queue<int> q;
    for(int i=0; i<v; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(int x: adj[node])
        {
            indegree[x]--;
            if(indegree[x] == 0)
                q.push(x);
        }
    }
    
    return ans;
}