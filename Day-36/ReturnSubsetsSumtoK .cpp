/*
Given an integer array 'ARR' of size 'N' and an integer 'K', return all the subsets of 'ARR' which sum to 'K'.
Subset of an array 'ARR' is a tuple that can be obtained from 'ARR' by removing some (possibly all) elements of 'ARR'.
Note :

The order of subsets is not important. 

The order of elements in a particular subset should be in increasing order of the index.
*/

#include<bits/stdc++.h>
using namespace std;
void findsubset(int i, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans,int n,int k)
{
    if(k == 0)  
    {
        ans.push_back(ds);
    }
    
    if(i>= n) return;
    
    for(; i<n; i++)
    {   
        ds.push_back(arr[i]);
        findsubset(i+1,arr,ds,ans,n,k-arr[i]);
        ds.pop_back();
    }
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> ds;
    findsubset(0,arr,ds,ans,n,k);
    
//     sort(arr.begin(),arr.end());
    return ans;
}