/*
You are given an unweighted directed graph of 'V' vertices and 'E' edges. Your task is to print all the strongly connected components (SCCs) present in the graph.
*/

#include<bits/stdc++.h>
using namespace std;
void dfs(int v, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    vis[v] = 1;
    for(auto it : adj[v])
    {
        if(!vis[it])
            dfs(it,vis,adj,st);
    }
    
    st.push(v);
}

void revdfs(int v, vector<int> &vis, vector<int> trans[] , vector<int> &res)
{
    vis[v] =1;
    res.push_back(v);
    for(auto it : trans[v])
    {
        if(!vis[it])
            revdfs(it,vis,trans,res);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int> adj[n];
    for(auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }
    
    vector<int> vis(n,0);
    stack<int> st;
    for(int i = 0; i<n; i++)
    {
        if(!vis[i])
            dfs(i,vis,adj,st);
    }
    
    vector<int> trans[n];
    for(int i = 0; i<n; i++)
    {
        vis[i] = 0;
        for(auto it : adj[i])
        {
            trans[it].push_back(i);
        }
    }
    
    vector<vector<int>> ans;
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        
        if(!vis[node])
        {
            vector<int> res;
            revdfs(node,vis,trans,res);
            ans.push_back(res);
        }
    }
    
    return ans;
}