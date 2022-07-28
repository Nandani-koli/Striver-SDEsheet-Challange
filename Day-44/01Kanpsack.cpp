/*
A thief is robbing a store and can carry a maximum weight of ‘W’ into his knapsack. There are 'N' items 
available in the store and the weight and value of each item is known to the thief. Considering the 
constraints of the maximum weight that a knapsack can carry, you have to find the maximum profit that a 
thief can generate by stealing items.

Note: The thief is not allowed to break the items.
For example, N = 4, W = 10 and the weights and values of items are weights = [6, 1, 5, 3] and 
values = [3, 6, 1, 4]. Then the best way to fill the knapsack is to choose items with weight 6, 1 and  3. 
The total value of knapsack = 3 + 6 + 4 = 13.

*/

//Approach 1:- memoization recursive approach
#include<bits/stdc++.h>
using namespace std;
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp){

    if(ind == 0){
        if(wt[0] <=W) return val[0];
        else return 0;
    }
    
    if(dp[ind][W]!=-1)
        return dp[ind][W];
        
    int notTaken = 0 + knapsackUtil(wt,val,ind-1,W,dp);
    
    int taken = INT_MIN;
    if(wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt,val,ind-1,W-wt[ind],dp);
        
    return dp[ind][W] = max(notTaken,taken);
}
int maxProfit(vector<int> &val, vector<int> &wt, int n, int w)
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return knapsackUtil(wt, val, n-1, w, dp);
}

//Approch 2:- Tabulation

#include<bits/stdc++.h>
int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    
    for(int i=wt[0]; i<=W; i++){
        dp[0][i] = val[0];
    }
    
    for(int ind =1; ind<n; ind++){
        for(int cap=0; cap<=W; cap++){
            
            int notTaken = 0 + dp[ind-1][cap];
            
            int taken = INT_MIN;
            if(wt[ind] <= cap)
                taken = val[ind] + dp[ind-1][cap - wt[ind]];
                
            dp[ind][cap] = max(notTaken, taken);
        }
    }
    
    return dp[n-1][W];
}