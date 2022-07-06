/*
You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.

Sample Input 1 :

6
6 2 1 3 7 5

Sample Output 1 :

6 4 2 2 3 4

*/

#include<bits/stdc++.h>
using namespace std;
void insert(int num,priority_queue<int,vector<int>> &maxheap, 
priority_queue<int, vector<int>, greater<int>> &minheap)
{
    if(maxheap.empty() || maxheap.top() > num)
    {
        maxheap.push(num);
    }
    else{
        minheap.push(num);
    }
    if(maxheap.size() > minheap.size() +1)
    {
        minheap.push(maxheap.top());
        maxheap.pop();
    }
    else if(minheap.size() > maxheap.size() + 1)
    {
        maxheap.push(minheap.top());
        minheap.pop();
    }
}

int median(priority_queue<int,vector<int>> &maxheap, 
priority_queue<int, vector<int>, greater<int>> &minheap)
{
    if(maxheap.size() == minheap.size())
    {
        return (maxheap.top()+minheap.top())/2.0;
    }
    else if(maxheap.size() > minheap.size())
    {
        return maxheap.top();
    }
    else{
        return minheap.top();
    }
}
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int,vector<int>> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;
    vector<int> ans;
    for(int i = 0; i<n; i++)
    {
        insert(arr[i],maxheap,minheap);
        ans.push_back(median(maxheap,minheap));
    }
    
    for(int i =0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}