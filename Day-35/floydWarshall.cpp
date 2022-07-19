/*
You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N' and ‘M’ edges. Each edge connecting two nodes 'u' and 'v' has a weight 'w' denoting the distance between them.
Your task is to find the length of the shortest path between the ‘src’ and ‘dest’ vertex given to you in the graph using Flloyd warshall’s algorithm. The graph may contain negatively weighted edges.
*/

#include<bits/stdc++.h>
using namespace std;
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int>> dist(n+1, vector<int>(n+1, 1e9));
    for(auto edge: edges)
    {
        dist[edge[0]][edge[1]]=edge[2];
    }
    int num=n+1;
    while(num--){
            dist[num][num]=0;    
    }
    
    for(int k = 1; k<=n; k++)
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if((dist[i][j] > dist[i][k] + dist[k][j]) && (dist[i][k]!=1e9 && dist[k][j]!=1e9))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    return dist[src][dest];
}