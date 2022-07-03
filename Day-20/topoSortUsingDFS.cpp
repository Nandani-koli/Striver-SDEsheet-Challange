/*
A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.
Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG. Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.
*/

#include <vector>
#include<stack>
#include<iostream>
using namespace std;

void toposort(int node,vector<bool>&vis,stack<int>&st, vector<int>g[])
{
    vis[node] = 1;
    for(auto it: g[node])
    {
        if(!vis[it])
        { 
           toposort(it,vis,st,g);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

   vector<int> ans;
    vector<int> adj[v];
                         
    for(int i = 0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    stack<int> st;
    vector<bool> vis(v,0);
    for(int i =0; i<v; i++)
    {
        if(!vis[i])
        {
            toposort(i,vis,st,adj);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
   
    return ans;
}