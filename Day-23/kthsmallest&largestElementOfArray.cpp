/*
You are given an array ‘Arr’ consisting of ‘N’ distinct integers and a positive integer ‘K’. Find out Kth smallest and Kth largest element of the array. It is guaranteed that K is not greater than the size of the array.
Example:

Let ‘N’ = 4,  ‘Arr’ be [1, 2, 5, 4] and ‘K’ = 3.  
then the elements of this array in ascending order is [1, 2, 4, 5].  Clearly, the 3rd smallest and largest element of this array is 4 and 2 respectively.
*/

#include <bits/stdc++.h>
using namespace std;

//method 1
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
    int kthLargest=0;
    int kthSmallest=0;
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    vector<int>ans(2);
    
    for(int i=0;i<n;i++){
        maxh.push(arr[i]);
        if(maxh.size()>k){
            maxh.pop();
        }
    }
    ans[0]=maxh.top();
    
    for(int i=0;i<n;i++){
        minh.push(arr[i]);
        if(minh.size()>k){
            minh.pop();
        }
    }
    ans[1]=minh.top();
    
    return ans;
}

//method 2

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
     sort(arr.begin(),arr.end());

   vector<int> res;

   res.push_back(arr[k-1]);

   res.push_back(arr[n-k]);

   return res;
}