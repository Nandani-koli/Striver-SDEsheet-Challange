/*
You have been given a grid containing some oranges. Each cell of this grid has one of the three integers values:
Value 0 - representing an empty cell.
Value 1 - representing a fresh orange.
Value 2 - representing a rotten orange.
Every second, any fresh orange that is adjacent(4-directionally) to a rotten orange becomes rotten.
Your task is to find out the minimum time after which no cell has a fresh orange. If it's impossible to rot all the fresh oranges then print -1.
Note:

1. The grid has 0-based indexing.
2. A rotten orange can affect the adjacent oranges 4 directionally i.e. Up, Down, Left, Right.

*/


#include<bits/stdc++.h>
using namespace std;
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
     int ans=-1;
    int fresh=0;
    queue<pair<int,int>>q;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
                q.push({i,j});
            if(grid[i][j]==1)
                fresh++;
        }
    }
    
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    while(!q.empty())
    {
        int s=q.size();
        while(s--)
        {
            pair<int,int>p=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int r=p.first+dx[i];
                int c=p.second+dy[i];
                if(r>=0 && r<n && c>=0 &&c<m && grid[r][c]==1)
                {
                    grid[r][c]=2;
                    q.push({r,c});
                    fresh--;
                }
            }
        }
        ans++;
    }
    
    if(fresh>0)
        return -1;
    
    if(ans==-1)
        return 0;
    
    return ans;
}