/*
You are given a string (STR) of length N.
Your task is to find the longest palindromic substring. If there is more than one palindromic substring with the maximum length, return the one with the smaller start index.
Note:

A substring is a contiguous segment of a string.

For example :

The longest palindromic substring of "ababc" is "aba", since "aba" is a palindrome and it is the longest substring of length 3 which is a palindrome. There is another palindromic substring of length 3 is "bab". Since starting index of "aba" is less than "bab", so "aba" is the answer.

*/
#include<bits/stdc++.h>
using namespace std;
string expand(int l,int r,string s){
    while(l>=0 && r<=s.size()){
        if(s[l]!=s[r]){
            break;
        }
        l--;
        r++;
    }
    return s.substr(l+1,r-l-1);
}
string longestPalinSubstring(string str)
{
    // Write your code here.
     string longest;
    int n=str.size();
    for(int i=0;i<n;i++){
        string odd=expand(i,i,str);
        if(odd.size()>longest.size()){
            longest=odd;
        }
    }
    for(int i=0;i<n;i++){
        string even=expand(i,i+1,str);
        if(even.size()>longest.size()){
            longest=even;
        }
    }
    return longest;
}
