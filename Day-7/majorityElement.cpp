/*
You have been given an array/list 'ARR' consisting of 'N' integers. Your task is to find the majority element in the array. If there is no majority element present, print -1.
Note: A majority element is an element that occurs more than floor('N' / 2) times in the array.
INPUT->
5
2 3 9 2 2
OUTPUT->
2
*/
#include <bits/stdc++.h> 
using namespace std;
int findMajorityElement(int arr[], int n) {
    int count = 0;
    int element = 0;
    for(int num = 0; num < n; num++)
    {
        if(count == 0)
        {
            element = arr[num];
        }
        if(arr[num] == element)
        {
            count += 1;
        }
        else count -= 1;
    }
    
    count = 0;
    for(int i = 0; i<n; i++)
    {
        if(arr[i] == element)
        {
            count++;
        }
    }
    
    if(count > n/2)
    {
        return element;
    } return -1;
}
int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<findMajorityElement(arr,n)<<endl;
}
