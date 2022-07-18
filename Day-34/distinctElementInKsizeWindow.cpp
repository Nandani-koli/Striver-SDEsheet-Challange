/*
You are given an array ‘ARR’ of size ‘N’ and an integer ‘K’. Your task is to find the total number of distinct elements present in every ‘K’ sized window of the array. A ‘K’ sized window can also be viewed as a series of continuous ‘K’ elements present in the sequence.
Note:

1. The size of ‘ARR’ will always be greater than or equal to the ‘K’.
2. Here window refers to a subarray of ‘ARR’. Hence ‘K’ sized window means a subarray of size ‘K’.
3. You are not required to print the output explicitly. It has already been taken care of. Just implement the function and return an array of the count of all distinct elements in the ‘K’ size window.

*/
#include<bits/stdc++.h>
using namespace std;
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
	vector<int> ans;
    int n = arr.size();
    unordered_map<int,int> umap;
    for(int i =0; i<k; i++)
    {
        umap[arr[i]]++;
    }
    ans.push_back(umap.size());
    for(int i = k; i<n; i++)
    {
        umap[arr[i-k]]--;
        if(umap[arr[i-k]] == 0)
            umap.erase(arr[i-k]);
        
        umap[arr[i]]++;
        ans.push_back(umap.size());
    }
    
    return ans;
}
