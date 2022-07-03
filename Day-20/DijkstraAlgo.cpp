/*
You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) and ‘E’ edges. Each edge connecting two nodes (‘X’,’Y’) will have a weight denoting the distance between node ‘X’ and node ‘Y’.
Your task is to find the shortest path distance from the source node, which is the node labeled as 0, to all vertices given in the graph.

INPUT->
5 7
0 1 7
0 2 1
0 3 2
1 2 3
1 3 5 
1 4 1
3 4 7

OUTPUT->
0 4 1 2 5
*/

#include<bits/stdc++.h>
using namespace std;
void shortestpath(int src, vector<int>&dist, vector<pair<int,int>> g[])
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({0,src});

    while (!pq.empty())
    { 
       int node = pq.top().second;
       int distance = pq.top().first;
       pq.pop();

       for(auto it : g[node])
       {
           if(dist[it.first] > distance + it.second)
           {
                dist[it.first] = distance + it.second;
                pq.push({dist[it.first] ,it.first});
           }
       }
    }
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<pair<int,int>> adj[vertices];
    vector <int> dist(vertices,INT_MAX);
    for(int i =0; i<edges; i++)
    {
       adj[vec[i][0]].push_back({vec[i][1],vec[i][2]});
       adj[vec[i][1]].push_back({vec[i][0],vec[i][2]});
    }
      shortestpath(source,dist,adj);
    
    return dist;
}
