/*
You have been given two strings 'STR1' and 'STR2'. You have to check whether the two strings are anagram to each other or not.
Note:

Two strings are said to be anagram if they contain the same characters, irrespective of the order of the characters.
*/

#include<bits/stdc++.h>
using namespace std;
bool areAnagram(string &str1, string &str2){
    // Write your code here.
     int n=str1.length();
    int m=str2.length();
    if(m!=n) return false;
    unordered_map<char, int> mp;
    for(int i=0; i<n; i++)
    {
        mp[str1[i]]++;
    }
    for(int i=0; i<n; i++)
    {
        if(mp[str2[i]]==0)
            return false;
    }
    return true;
}