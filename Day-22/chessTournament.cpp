/*
Chess tournament is going to be organized in Ninjaland. There will be C chess players going to attend the tournament. All the players will be staying in a hotel. The hotel has N free rooms available for the players, where one player will choose one room to live in. The ith room is at position[i] in the hotel. All rooms are in distinct positions.
Focus level of a chess player is defined as the minimum distance between his room and the room of another player. The overall focus of a tournament is defined as the minimum focus level among all players. You as an organizer obviously want the overall focus as high as possible so you assign the rooms to players such that the overall focus is as high as possible.
For example,

let say we have 3 players and 5 rooms available and the rooms are at positions:  1 2 3 4 6
Here the optimal allocation is in rooms 1 3 6 and the overall focus level is 2.
*/

#include<bits/stdc++.h>
using namespace std;
bool allocateRoom(vector<int> &position, int n, int c,int mid)
{
    int coordinate = position[0], cnt = 1;
    for(int i = 1; i<n; i++)
    {
        if(position[i] - coordinate >= mid)
        {
            cnt++;
            coordinate = position[i];
        }
        if(cnt == c)   return true;
    }
    return false;
}
int chessTournament(vector<int> positions , int n ,  int c)
{
    sort(positions.begin(),positions.end());
    int low = 1, high = positions[n-1] - positions[0] ;
    int ans;
    while(low <= high)
    {
        int mid = (low+high)/2;
        
        if(allocateRoom(positions,n,c,mid))
        {
            ans = mid;
            low = mid +1;
        }
        else{
            high = mid -1;
        }
    }
    return ans;
}