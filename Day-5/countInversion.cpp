/*
For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.

A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').


//INPUT ->
5
2 5 1 3 4
// OUTPUT->
4
1 2 3 4 5 
*/
#include <iostream>
using namespace std;
long long merge(long long arr[], long long low, long long high)
{
    long long mid = low + (high - low)/2;
    long long n1 = mid-low+1;
    long long n2 = high - mid;
    long long a[n1];
    long long b[n2];

    for(long long i =0; i<n1; i++)
    {
        a[i] = arr[low+i];
    }
    for(long long i =0; i<n2; i++)
    {
        b[i] = arr[mid+1+i];
    }

    long long i = 0, j =0;
    long long k = low;
    long long count = 0;
    while(i < n1 && j < n2)
    {
        if(a[i] < b[j])
        {
            arr[k] = a[i];
            k++,i++;
        }
        else{
            arr[k] = b[j];
            k++,j++;
            count = count + (n1- i);
        }
    }

    while(i < n1)
    {
        arr[k] = a[i];
        k++,i++;
    }
    while(j < n2)
    {
        arr[k] = b[j];
        k++,j++;
    }
    return count;
}
long long mergeSort(long long arr[], long long low,long long high)
{
    long long count = 0;
    if(low<high)
    {
        long long mid = low + (high - low)/2;
        count += mergeSort(arr,low,mid);
        count += mergeSort(arr,mid+1,high);

        count += merge(arr,low,high);
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    long long arr[n];
    for(int i =0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<mergeSort(arr,0,n-1)<<endl;

    for(int i =0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}