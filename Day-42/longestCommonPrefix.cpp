/*
you are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest common prefix among all these strings. If there is no common prefix, you have to return an empty string.
A prefix of a string can be defined as a substring obtained after removing some or all characters from the end of the string.
For Example:

Consider ARR = [“coding”, ”codezen”, ”codingninja”, ”coders”]
The longest common prefix among all the given strings is “cod” as it is present as a prefix in all strings. Hence, the answer is “cod”.
*/

//brute force O(n*m)
#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = "";
    for(int i = 0; i< arr[0].length(); i++)
    {
        char ch = arr[0][i];
        bool match = true;
        for(int j = 1; j<n;j++)
        {
            if(arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if( match == false)
        {
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    
    return ans;
}


