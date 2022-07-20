/*
You are given an array ‘Arr’ of ‘N’ positive integers. You are also given a positive integer ‘target’.
Your task is to find all unique combinations of the array ‘Arr’ whose sum is equal to ‘target’. Each number in ‘Arr’ may only be used once in the combination.
Elements in each combination must be in non-decreasing order and you need to print all unique combinations in lexicographical order.
Note:

In lexicographical order, combination/array  ‘A’  comes before array ‘B’ if ‘A’ is the prefix of array ‘B’, or if none of them is a prefix of the other and at the first position where they differ integer in ‘A’ is smaller than the integer in ‘B’.

*/

#include<bits/stdc++.h>
using namespace std;
void findsubset(int index, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans,int n,int k)
{
    if(k == 0)  
    {
        ans.push_back(ds);
        return;
    }
    
    for(int i = index; i<n; i++)
    {   
        if(i != index && arr[i] == arr[i-1])    continue;
        if(arr[i] > k) break;
        ds.push_back(arr[i]);
        findsubset(i+1,arr,ds,ans,n,k-arr[i]);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    // Write your code here.
    sort(arr.begin(),arr.end());
     vector<vector<int>> ans;
    vector<int> ds;
    findsubset(0,arr,ds,ans,n,target);
    
    return ans;
}

