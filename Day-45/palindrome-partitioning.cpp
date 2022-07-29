/*
Given a string ‘str’. Find the minimum number of partitions to make in the string such that every partition
of the string is a palindrome.

Given a string, make cuts in that string to make partitions containing substrings with size at least 1, 
and also each partition is a palindrome. For example, consider “AACCB” we can make a valid partition like 
A | A | CC | B. Among all such valid partitions, return the minimum number of cuts to be made such that 
the resulting substrings in the partitions are palindromes.

The minimum number of cuts for the above example will be AA | CC | B. i.e 2 cuts

1) We can partition the string after the first index and before the last index.

2) Each substring after partition must be a palindrome.

3) For a string of length ‘n’, if the string is a palindrome, then a minimum 0 cuts are needed.  

4) If the string contains all different characters, then ‘n-1’ cuts are needed.

5) The string consists of upper case English alphabets only with no spaces.

*/

//memoization a recursive solution

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int i,int j,string a)
{
    while(i<j)
    {
        if(a[i]!=a[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int f(int i,int n,string&a,vector<int>&dp)
{
    if(i==n)
        return 0;
    
    if(dp[i]!=-1)
        return dp[i];
    int mincost=INT_MAX;
    for(int j=i;j<n;j++)
    {
        if(isPalindrome(i,j,a))
        {
            int cost = 1+f(j+1,n,a,dp);
            mincost=min(cost,mincost);
        }        
    }
    return dp[i]=mincost;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n=str.length();
    vector<int> dp(n,-1);
    return f(0,n,str,dp)-1;
}


//Tabulation

bool isPalindrome(int i,int j,string a)
{
    while(i<j)
    {
        if(a[i]!=a[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int palindromePartitioning(string str) {
    // Write your code here
     int n= str.length();
    vector<int> dp(n+1, 0);
    for(int ind = n-1; ind>=0;ind--)
    {
        int count = INT_MAX;
        for(int j = ind; j<n; j++)
        {
            if(isPalindrome(ind, j, str))
            {
                int var = 1 + dp[j+1];
                count = min(var, count);
            }
            
        }
        dp[ind] = count;
    }
    return dp[0] - 1;
}
