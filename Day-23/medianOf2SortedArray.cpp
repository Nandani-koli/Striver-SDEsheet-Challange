/*
You are given two sorted arrays 'A' & 'B' of sizes 'N' & 'M'. You need to find the median of the two arrays when merged. If the total number of elements i.e., N + M is even then the median will be the mean of two medians.
Example:

Let array A = { 2, 4, 6, 8 } and array B = { 1, 3, 5, 7 }. 
The array after merging A and B will be { 1, 2, 3, 4, 5, 6, 7, 8 }.
Here two medians are 4 & 5. So the median will be a mean of 4 & 5, which is 4.5.
*/
#include<bits/stdc++.h>
using namespace std;
double median(vector<int> a, vector<int> b)
{
    if(b.size()<a.size()){
        return median(b,a);
    }
    int n=a.size();
    int m=b.size();
    
    int low=0;
    int high=n;
    
    while(low<=high){
        int p1=(low+high)/2;       // partition 1
        int p2=((n+m+1)/2)-p1;   // partition 2
        
        int l1=p1==0 ? INT_MIN : a[p1-1];
        int l2=p2==0 ? INT_MIN : b[p2-1];
        
        int r1=p1==n ? INT_MAX : a[p1];
        int r2=p2==m ? INT_MAX : b[p2];
        
        if(l1<=r2 && l2<=r1){
            if((n+m)%2==0){
                return (double)(((double)max(l1,l2)+(double)min(r1,r2))/2);
            }
            else{
                return max(l1,l2);
            }
        }
        else if(l1>r2){
            high=p1-1;
        }
        else{
            low=p1+1;
        }
    }
    return 0;
    
}
