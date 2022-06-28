/*
You have been given a long type array/list 'ARR' of size 'N'. It represents an elevation map wherein 'ARR[i]' denotes the elevation of the 'ith' bar. Print the total amount of rainwater that can be trapped in these elevations.
INPUT->
6
3 0 0 2 0 4

OUTPUT->
10
*/

#include <bits/stdc++.h> 
using namespace std;

//brute force O(n^2)
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long ans = 0;
    for(int i =0; i<n; i++)
    {
        int j = i;
        long leftmax =0, rightmax = 0;
        while(j >= 0)
        {
            leftmax = max(leftmax, arr[j]);
            j--;
        }
        
        j = i;
        while(j < n)
        {
            rightmax = max(rightmax, arr[j]);
            j++;
        }
        
        ans += min(leftmax,rightmax) - arr[i];
    }
    
    return ans;
}

//better Approach TC:- O(3n) SC-> O(n+n)
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long trapwater = 0;
    long prefix[n], suffix[n];
    prefix[0] = arr[0];
    suffix[n-1] = arr[n-1];
    
    for(int i = 1; i<n; i++)
    {
        prefix[i] = max(prefix[i-1] , arr[i]);
    }
    
    for(int i = n-2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i+1], arr[i]);
    }
    
    for(int i = 0; i<n; i++)
    {
        trapwater += min(prefix[i] , suffix[i]) - arr[i];
    }
    
    return trapwater;
} 

//Optimized used 2-pointer approach TC-> O(n) SC-> O(1)
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long l = 0,r= n-1, rightmax =0,leftmax = 0;
    long ans = 0;
    while(l <= r)
    {
        if(arr[l] <= arr[r])
        {
            if(leftmax <= arr[l])
                    leftmax = arr[l];
            else 
                ans +=leftmax - arr[l];
            
            l++;
        }
        else{
            if(rightmax <= arr[r])
                rightmax = arr[r];
            else  
                ans += rightmax - arr[r];
            
            r--;
        }
    }
    
    return ans;
}