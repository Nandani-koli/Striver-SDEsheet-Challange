/*
Given a string ‘STR’ of length 'N'. Implement the atoi function. If there are no numbers in the string, return 0.
In other words, given a string ‘STR’ convert the string to an integer.
Example :

Give string : ”123456”, we return the integer value ‘123456’.

The string can contain any ascii characters. If the character in the string is not a number, ignore it.
Example :

Given string : ”#messi10”, we return 10 as other characters “messi” are not numbers hence we skip them.

*/

#include<bits/stdc++.h>
int atoi(std::string str) {
    // Write your code here.
    int sign = 1;
    int i = 0;
    int ans = 0;
    if(str[i] == '-')
    {
        sign = -1;
        i++;
    }
   for(; i<str.length(); i++)
   {
       if(str[i]-'0' >= 0 && str[i]-'0' <= 9)
       {
           ans = ans * 10 + str[i]-'0';
       }
   }
    return ans*sign;
}