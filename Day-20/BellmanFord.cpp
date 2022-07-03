/*
You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N' and ‘M’ edges. Each edge connecting two nodes 'u' and 'v' has a weight 'w' denoting the distance between them.
Your task is to find the length of the shortest path between the ‘src’ and ‘dest’ vertex given to you in the graph. The graph may contain negatively weighted edges.

It's guaranteed that the graph doesn't contain self-loops and multiple edges. Also the graph does not contain negative weight cycles.


The first line of each test case contains four single space-separated integers ‘N’,  ‘M’ , ‘src’ and ‘dest’ denoting the number of vertices, the number of edges in the directed graph the source vertex and the destination vertex respectively.

The next ‘M’ lines each contain three single space-separated integers ‘u’, ‘v’, and ‘w’, denoting an edge from vertex ‘u’ to vertex ‘v’, having weight ‘w’.

INPUT->
4 4 1 4
1 2 4
1 3 3
2 4 7 
3 4 -2

OUTPUT->
1

*/

#include<bits/stdc++.h>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1,INT_MAX);
    dist[src] = 0;
    for(int i = 1; i<=n; i++)
    {
        for(auto eg : edges)
        {
            if(dist[eg[0]] != INT_MAX && dist[eg[0]] + eg[2] < dist[eg[1]]){
                dist[eg[1]] = dist[eg[0]] + eg[2];
            }
        }
    }
    if(dist[dest] == INT_MAX)
    {
        return 1000000000;
    }
    return dist[dest];
}