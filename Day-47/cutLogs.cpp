/*
Ninja is a log cutter. He has a ‘K’ number of axes and an infinite amount of logs. But, Ninja has a log
 cutting stand that has a capacity of ‘N’, which means he can only try to cut at max ‘N’ logs in one go. 
All the axes are exactly the same and can cut up to some logs in one go. If we try to cut more logs than
 its capacity the axe will break.
To improve efficiency, Ninja wants to know how many logs he can cut with an axe in one go without breaking it.
But, he wants to know this is the minimum number of moves and in the allotted number of axes.

Can you calculate the minimum number of moves in which Ninja can know the limit of axes?
Some points to notice about axes are:

1. An axe that is used to cut a lesser or equal number of logs than its limit can be used again.

2. An axe that is used to cut more logs than its limit will be broken. Thus, it cannot be used again.

3. All the axes have the same limit of cutting logs until broken.

4. An axe may also cut N logs or may not even cut a single log.


*/
#include<bits/stdc++.h>
using namespace std;

int dp[10005][105];
int Solve(int n,int e)
{
   if(e==1)
     return n;
    if(n==1 or n==0)
         return n;
    if(dp[n][e]!=-1)
     return dp[n][e];
    int ans=INT_MAX;
    int low=1,high=n;
   while(low<=high)
   {
        int mid=(low+high)/2;
        int left=Solve(mid-1,e-1);
        int right=Solve(n-mid,e);
        int temp=1+max(left,right);
         if(left>right)
            high=mid-1; 
       else 
            low=mid+1;
        ans=min(ans,temp);
    }
    return dp[n][e]=ans;
}
int cutLogs(int k, int n)
{
    // Write your code here.
    memset(dp,-1,sizeof(dp));
   return Solve(n,k);
}

