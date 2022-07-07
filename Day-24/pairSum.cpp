/*
You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.
Note:

Each pair should be sorted i.e the first value should be less than or equals to the second value. 

Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.

INPUT->
5 5
1 2 3 4 5

OUTPUT->
1 4
2 3
*/

#include <bits/stdc++.h> 
using namespace std;

//Brute Force Approach O(n^2)
vector<vector<int>> pairSum(vector<int> &arr, int s){

    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i<arr.size(); i++)
    {
        for(int j = i+1 ; j < arr.size(); j++)
        {
            if(arr[i]+arr[j] == s)
            {
            ans.push_back(vector<int> {arr[i],arr[j]});
            }
        }
    }
    return ans;
}

//Approach 2 using Unordered map
#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    vector<vector<int>> ans;
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        int count = mp[s-arr[i]];
        while(count){
            ans.push_back({min(arr[i],s-arr[i]),max(arr[i],s-arr[i])});
            count--;
        }
        
        mp[arr[i]]+=1;
    }
    
    sort(ans.begin(),ans.end());
    
    return ans;
}

