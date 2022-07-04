/*
You are given an undirected connected weighted graph having ‘N’ nodes numbered from 1 to 'N'. A matrix ‘E’
of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node E[i][0] 
to node E[i][1]. You are supposed to return the minimum spanning tree where you need to return weight for each edge in the MST.
*/

#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
     vector<pair<pair<int, int>, int>> ans;
        vector<pair<int,int>> adj[n+1];
        for(auto it:g)
        {
         adj[it.first.first].push_back({it.first.second,it.second});
         adj[it.first.second].push_back({it.first.first,it.second});
        }
    
    int key[n+1],parent[n+1];
    bool mst[n+1];
    
    for(int i = 1; i<=n; i++)
        key[i] = INT_MAX, mst[i] = false, parent[i] = -1;
    
    
    key[1] = 0;
    parent[1] = -1;
    for(int i = 0; i<n-1; i++)
    {
        int min = INT_MAX;
        int node;
        
        for(int j = 1; j <= n; j++)
        {
            if(mst[j] == false && key[j] < min)
            {
                min = key[j];
                node = j;
            }
        }
        mst[node] = true;
        
        for(auto it : adj[node])
        {
            int d = it.first;
            int w = it.second;
            if(mst[d] == false && key[d] > w)
            {
                key[d] = w;
                parent[d] = node;
            }
        }
    }
    
    for(int i = 1; i<=n; i++)
    {
        if(parent[i] != -1)
            ans.push_back({{parent[i],i}, key[i]});
    }
    
    return ans;
}

