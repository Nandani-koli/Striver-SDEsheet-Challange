/*
Given a graph, check whether the graph is bipartite or not. Your function should return true if the given graph's vertices can be divided into two independent sets, ‘U’ and ‘V’ such that every edge (‘u’, ‘v’) either connects a vertex from ‘U’ to ‘V’ or a vertex from ‘V’ to ‘U’.
You are given a 2D array ‘edges’ which contains 0 and 1, where ‘edges[i][j]’ = 1 denotes a bi-directional edge from ‘i’ to ‘j’.
Note:

If edges[i][j] = 1, that implies there is a bi-directional edge between ‘i’ and ‘j’, that means there exists both edges from ‘i’ to ‘j’ and to ‘j’ to ‘i’.

TC:- O(v+e)
SC:- O(v+e)+O(v)+O(v)
*/


#include<bits/stdc++.h>
using namespace std;
bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; 
            }
        }
    }
    return true; 
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    int n = edges[0].size();
    vector<int> adj[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(edges[i][j]==1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(bipartiteBfs(i,adj,color)==false) return false;
        }
    }
    return true;
    
}