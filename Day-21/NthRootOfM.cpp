/*
You are given two positive integers N and M. You have to find the Nth root of M i.e. M^(1/N).
Note:

N'th root of an integer M is a real number, which when raised to the power N gives M as a result.

N'th root of the M should be correct up to 6 decimal places.

INPUT->
3 27

OUTPUT->
3.000000

*/

double multi(double num,int n)
{
    double ans = 1.0;
    for(int i =1; i<=n; i++)
    {
        ans = ans * num;
    }
    return ans;
}
double findNthRootOfM(int n, long long m) {
	// Write your code here.
    double low = 1;
    double high = m;
    double eps = 1e-8;
    while((high-low) > eps)
    {
        double mid = (low+high)/2.0;
        if(multi(mid,n) < m)
        {
            low = mid;
        }
        else{
            high = mid;
        }
    }
    
    return low;
}
