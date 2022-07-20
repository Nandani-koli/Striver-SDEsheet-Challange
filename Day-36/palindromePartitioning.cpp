/*
You are given a string 'S'. Your task is to partition 'S' such that every substring of the partition is a palindrome. You need to return all possible palindrome partitioning of 'S'.
Note: A substring is a contiguous segment of a string.
For Example:

For a given string “BaaB”
3 possible palindrome partitioning of the given string are:
{“B”, “a”, “a”, “B”}
{“B”, “aa”, “B”}
{“BaaB”}
Every substring of all the above partitions of “BaaB” is a palindrome.

*/

#include<bits/stdc++.h>
using namespace std;

bool ispalindrom(string &s,int st,int ed)
{
    while(st <= ed)
    {
        if(s[st++] != s[ed--])
            return false;
    }
    return true;
}
void stringpartition(int index,string &s,vector<string> &ds,vector<vector<string>> &ans)
{
    if(index == s.size())
    {
        ans.push_back(ds);
        return;
    }
    
    for(int i = index; i< s.size(); ++i)
    {
        if(ispalindrom(s,index,i))
        {
            ds.push_back(s.substr(index, i - index + 1));
            stringpartition(i+1,s,ds,ans);
            ds.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> ds;
    stringpartition(0,s,ds,ans);
    return ans;
}
