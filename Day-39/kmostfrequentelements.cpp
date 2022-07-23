/*
You are given an Integer array ‘ARR’ and an Integer ‘K’. Your task is to find the ‘K’ most frequent elements in ‘ARR’. Return the elements sorted in ascending order.
For Example:

You are given ‘ARR’ = {1, 2, 2, 3, 3} and ‘K’ = 2. Then the answer will {2, 3} as 2 and 3 are the elements occurring most number of times.

*/
#include<bits/stdc++.h>
using namespace std;

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    map<int,int> mp;
    priority_queue<pair<int,int>> pq;
    vector<int> ans;
    
    //1:- first count number of appearance of an element
    for(auto i : arr)
    {
        mp[i]++;
    }
    
    //2:- store according to number of time it occur in maxheap
    for(auto it : mp)
    {
        pq.push({it.second,it.first});
    }
    
    //4:- extract top k elements from maxheap
    while(k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    
    //5:- sort in ascending order
    sort(ans.begin(),ans.end());
   
    return ans;
}

int main()
{
    vector<int> arr = {7, 2, 5 ,8, 1, 7, 9, 4, 6, 1, 8, 9, 4 };
    int n = arr.size();
    int k = 5;
    vector<int> res;
    res = KMostFrequent(n,k,arr);

    for(int i = 0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}