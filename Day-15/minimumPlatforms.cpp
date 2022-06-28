/*
You have been given two arrays, 'AT' and 'DT', representing the arrival and departure times of all trains that reach a railway station.
Your task is to find the minimum number of platforms required for the railway station so that no train needs to wait.

INPUT->
6
900 940 950 1100 1500 1800
910 1200 1120 1130 1900 2000

OUTPUT->
3

*/

#include <bits/stdc++.h>
using namespace std;

//Brute Force O(n^2)
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    int ans = 1;
    for(int i = 0; i<n; i++)
    {
        int count = 1;
        for(int j = i+1; j<n; j++)
        {
            if((at[i] >= at[j] && at[i] <= dt[j]) || (at[j] >= at[i] && at[j] <= dt[i]))
            {
                count++;
            }
        }
        ans = max(ans,count);
    }
    return ans;
}

//Better approach O(nlogn)
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int count = 1;
    int ans = 1;
    int i = 1, j = 0;
    while(i < n && j < n)
    {
        if(at[i] <= dt[j])
        {
            count ++;
            i++;
        }
        else{
            count--;
            j++;
        }
        ans = max(ans,count);
    }
    return ans;
}