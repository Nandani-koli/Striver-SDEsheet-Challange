/*
You have been given a connected undirected weighted graph. Your task is to find the weight of the minimum spanning tree of the given graph.
A minimum spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles, and with the minimum possible total edge weight. A spanning tree’s weight is the sum of weights given to each edge of the spanning tree.
*/

#include<bits/stdc++.h>
using namespace std;
int find(int x, vector<int> &parent)
{
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x],parent);
}

void Unionn(int a,int b,vector<int> &parent, vector<int> &Rank)
{
    a = find(a,parent);
    b = find(b,parent);

    if(Rank[a] < Rank[b])
        parent[a] = b;
    else if(Rank[b] < Rank[a])
        parent[b] = a;
    else
        parent[a] = b, Rank[b]++;
}

bool comp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
    sort(graph.begin(),graph.end(),comp);
    
    vector<int> parent(n+1);
    vector<int> Rank(n+1,0);
    
    for(int i = 1; i<n+1; i++)
    {
        parent[i] = i;
    }
    
    int cost = 0;
    
    for(auto it : graph)
    {
        if(find(it[0] , parent) != find(it[1] , parent))
        {
            cost += it[2];
            Unionn(it[0],it[1],parent,Rank);
        }
    }
    
    return cost;
}