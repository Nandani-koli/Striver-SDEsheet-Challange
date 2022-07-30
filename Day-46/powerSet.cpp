/*
You are given a sorted array of 'N' integers. You have to generate the power set for this array where each subset of this power set is individually sorted.
A set is a well-defined collection of distinct elements. Power set P(ARR) of a set 'ARR' is defined as a set of all possible subsets of 'ARR'.
You have to return the array of subsets. The elements in the subset should be sorted in ascending order. The order of subsets in the array does not matter. Hence there can be more than 1 possible solution for a given array.

If we are given an array ARR=[1,2,3] then the power set P(ARR) of the set ARR is: [ [], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3] ]

For every subset 'X' present in power set P(ARR) of set ARR, X must be sorted i.e. in the example above:
P1(ARR) =  [ [], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3] ]
P2(ARR) =  [ [], [1], [1,2,3], [2], [1,2], [3], [1,3], [2,3] ]
P3(ARR) =  [ [], [1], [2], [1,2], [3], [1,3], [2,3], [2,3,1] ]
P1(ARR) and P2(ARR) will be considered correct power sets but P3(ARR) will not be considered correct because there the last subset [2, 3, 1] is not sorted.

*/

//using BITmanupulation
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>> ans;
    int n = v.size();
     
    for(int counter=0;counter<(1<<n);counter++){
          vector<int>subset;
        for(int i=0;i<n;i++){
          
            if(counter & (1<<i)){
                subset.push_back(v[i]);
                
            }
            
        }
        ans.push_back(subset);
        
    }
    
    return ans;
}


//Using recursion Backtracking

void solve(vector<int>&v, vector<vector<int>>& ans,vector<int>& temp, int ind, int n){
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        solve(v, ans, temp, ind+1, n);

        int ele=v[ind];
        temp.push_back(ele);
        solve(v, ans, temp, ind+1, n);
        temp.pop_back();
    }
    vector<vector<int>> pwset(vector<int>v)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=v.size();
        solve(v, ans, temp, 0, n);
        return ans;
    }