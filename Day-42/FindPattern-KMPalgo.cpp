/*
You are given two strings 'S' and 'P' consisting of lowercase English alphabets. Your task is to find whether the 'P' is present in 'S' as a substring or not.
Note

1. There may be more than one occurrence of 'P' in 'S'.
2. Some alphabets in the strings may be repeated.
*/

//simple logic
#include<string>
using namespace std;
bool findPattern(string p, string s)
{
    // Write your code here.
    if(s.length()!=0 && s.find(p)<=s.length())
    {  
       return true;
    }
    else
    {
        return false;
    }
}


//KMP ALGO

#include<bits/stdc++.h>
void find_lps(vector<int> &lps, string p)
{
    lps[0] = 0;
    int len = 0;
    for (int i=1;i<lps.size();i++)
    {
        while (len>0 && p[i] != p[len])
            len = lps[len-1];
        if (p[i] == p[len])
            len++;
        lps[i] = len;
    }
}
bool findPattern(string p, string s)
{
    // Write your code here.
    int m = p.length();
    int n = s.length();
    vector<int>lps(m,0);
    find_lps(lps,p);
    int len=0;
    for (int i=0;i<n;i++)
    {
        while (len>0 && p[len] != s[i])
            len = lps[len-1];
        if (p[len] == s[i])
            len++;
        if (len==m)
            return true;
    }
    return false;
}
