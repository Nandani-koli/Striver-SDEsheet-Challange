/*
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
You need to figure out the total number of ways W, in which you can make a change for value V using coins 
of denominations from D. Print 0, if a change isn't possible.

*/

//memoize a recursive solution:

#include<bits/stdc++.h>
using namespace std;

long countWaysToMakeChangeUtil(int *arr,int ind, int T, vector<vector<long
>>& dp){

    if(ind == 0){
        return (T%arr[0]==0);
    }
    
    if(dp[ind][T]!=-1)
        return dp[ind][T];
        
    long notTaken = countWaysToMakeChangeUtil(arr,ind-1,T,dp);
    
    long taken = 0;
    if(arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr,ind,T-arr[ind],dp);
        
    return dp[ind][T] = notTaken + taken;
}
long countWaysToMakeChange(int *arr, int n, int T)
{
    //Write your code here
    vector<vector<long>> dp(n,vector<long>(T+1,-1));
    return countWaysToMakeChangeUtil(arr,n-1, T, dp);
}


//Tabulation

#include<bits/stdc++.h>
long countWaysToMakeChange(int *arr, int n, int T)
{
    //Write your code here
    vector<vector<long>> dp(n,vector<long>(T+1,0));
    
    
    //Initializing base condition
    for(int i=0;i<=T;i++){
        if(i%arr[0]==0)
            dp[0][i]=1;
        // Else condition is automatically fulfilled,
        // as dp array is initialized to zero
    }
    
    for(int ind=1; ind<n;ind++){
        for(int target=0;target<=T;target++){
            long notTaken = dp[ind-1][target];
            
            long taken = 0;
            if(arr[ind]<=target)
                taken = dp[ind][target-arr[ind]];
                
            dp[ind][target] = notTaken + taken;
        }
    }
    
    return dp[n-1][T];
}
