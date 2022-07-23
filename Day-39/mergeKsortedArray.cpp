/*
You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). 
You need to merge all the given arrays/list such that the output array/list should be sorted in 
ascending order.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<int, vector<int>,greater<int>> minheap;
    
    for(int i = 0; i<k; i++)
    {
        for(int j = 0; j<kArrays[i].size(); j++)
        {
            minheap.push(kArrays[i][j]);
        }
    }
    
    vector<int> res;
    while(!minheap.empty())
    {
        res.push_back(minheap.top());
        minheap.pop();
    }
    
    return res;
}
