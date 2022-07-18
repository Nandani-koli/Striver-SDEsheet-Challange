/*
Given that integers are read from a data stream. Your task is to find the median of the elements read so far.
Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.
For example :

[2,3,4] - median is 3.
[2,3] - median is floor((2+3)/2) = 2.
*/
#include<bits/stdc++.h>
using namespace std;

void insert(int num,priority_queue<int,vector<int>> &maxheap, priority_queue<int, vector<int>, greater<int>> &minheap)
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

int median(priority_queue<int,vector<int>> &maxheap, priority_queue<int, vector<int>, greater<int>> &minheap)
{
    if(maxheap.size() == minheap.size())
    {
        return (maxheap.top()+minheap.top())/2;
    }
    else if(maxheap.size() > minheap.size())
    {
        return maxheap.top();
    }
    else{
        return minheap.top();
    }
}
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
    priority_queue<int,vector<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    vector<int> ans;
    for(int i = 0; i<n; i++)
    {
        insert(arr[i],maxheap,minheap);
        ans.push_back(median(maxheap,minheap));
    }
    return ans;
}
