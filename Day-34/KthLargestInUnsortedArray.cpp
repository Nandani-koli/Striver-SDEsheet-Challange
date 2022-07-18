/*
You are given an array consisting of 'N' distinct positive integers and a number 'K'. Your task is to find the kth largest element in the array.
Example:

Consider the array {2,1,5,6,3,8} and 'K' = 3, the sorted array will be {8, 6, 5, 3, 2, 1}, and the 3rd largest element will be 5.

Note:

1) Kth largest element in an array is the kth element of the array when sorted in non-increasing order. 

2) All the elements of the array are pairwise distinct.

*/

// Approach 1
#include<bits/stdc++.h>
using namespace std;

int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
     sort(arr.begin(),arr.end());
   return arr[size-K];
    
}


//Approach 2
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
    priority_queue<int> pq;
    for(int i=0; i<size; i++){
        pq.push(arr[i]);
    }
    while(K){
        if(K==1) return pq.top();
        pq.pop();
        K--;
    }
    return 0;
}
