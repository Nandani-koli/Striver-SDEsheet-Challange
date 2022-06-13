/*
You are given an array/list say ‘ARR’ of size ‘N’. We call pair (i, j) a Reverse Pair when i < j and 'ARR[i]' > 2 * 'ARR[j]'.
Your task is to find the number of Reverse Pairs present in given 'ARR'.

INPUT->
6
6 4 8 2 1 3

OUTPUT->
6
*/
#include <bits/stdc++.h> 
using namespace std;
int merge(vector<int> &nums, int low,int mid,int high)
{
    int count = 0;
    int j = mid+1;
    for(int i = low; i<=mid; i++)
    {
      while (j <= high && nums[i] > 2 * nums[j]) {
      j++;
    }
    count += (j - (mid + 1));
    }
    
    vector < int > t;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {

    if (nums[left] <= nums[right]) {
      t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  while (left <= mid) {
    t.push_back(nums[left++]);
  }
  while (right <= high) {
    t.push_back(nums[right++]);
  }

  for (int i = low; i <= high; i++) {
    nums[i] = t[i - low];
  }
    return count;
}
int mergeSort(vector<int> &arr,int low,int high)
{
    int pair =0;
    if(low<high)
    {
        int mid = (low+high)/2;
        pair += mergeSort(arr,low,mid);
        pair += mergeSort(arr,mid+1,high);
        
       pair += merge(arr,low,mid,high);
    }
    return pair;
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
   int ans =  mergeSort(arr,0,n-1);
   
   return ans;
}

int main()
{
    vector<int> arr = {6,4,8,2,1,3};
    cout<<reversePairs(arr,6)<<endl;
}
