/*
You have been given a matrix of ‘N’ rows and ‘M’ columns filled up with integers where every row is sorted in non-decreasing order. Your task is to find the overall median of the matrix i.e if all elements of the matrix are written in a single line, then you need to return the median of that linear array.
The median of a finite list of numbers is the "middle" number when those numbers are listed in order from smallest to greatest. If there is an odd number of observations, the middle one is picked. For example, consider the list of numbers [1, 3, 3, 6, 7, 8, 9]. This list contains seven numbers. The median is the fourth of them, which is 6.
*/
#include<bits/stdc++.h>
using namespace std;
int count(vector<vector<int>>&matrix,int mid)
{
    int cnt=0;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++)
    {
        auto it=upper_bound(matrix[i].begin(),matrix[i].end(),mid);
        cnt+=it-matrix[i].begin();
    }
    return cnt;
    
}
int getMedian(vector<vector<int>> &matrix)
{
     
        int n=matrix.size();
        int m=matrix[0].size();
    int left=1;
    int right=100000;
    while(left<=right)
    {
        int mid=(left+right)/2;
        int cnt=count(matrix,mid);
        if(cnt<=(n*m)/2)
        {
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return left;
}