/*
You are given a string of length N. You need to reverse the string word by word. There can be multiple spaces between two words and there can be leading or trailing spaces but in the output reversed string you need to put a single space between two words, and your reversed string should not contain leading or trailing spaces.
For example :

If the given input string is "  Welcome to   Coding  Ninjas", then you should return "Ninjas Coding to Welcome" as the reversed string has only a single space between two words and there is no leading or trailing space.

*/
#include<iostream>
#include<string>
using namespace std;

string reverseString(string str)
{
    // Write your code here.
    string ans = "";
    for(int i=str.length()-1; i>=0; i--)
    {
        if(str[i] == ' ')
            continue;
        int j=i;
        while(j>=0 and str[j]!=' ')
        {
            j--;
        }
        ans += (str.substr(j+1, i-j));
        ans += ' ';
        i=j;
    }
    return ans;
}