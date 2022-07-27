/*
You are given two strings 'S' and 'P' consisting of lowercase English alphabets. Your task is to find whether the 'P' is present in 'S' as a substring or not.
Note
using Z algorithm
1. There may be more than one occurrence of 'P' in 'S'.
2. Some alphabets in the strings may be repeated.
*/

#include<bits/stdc++.h>
using namespace std;
int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
    string newstr = p + "#" + s;
//     vector<int> z;
    int z[n+m+1];
    int i = 0;
    while(i< newstr.length())
    {
        if(i <= m) z[i] = 0;
        else{
            int left = 0,right = 0;
            if(newstr[left] == newstr[i])
            {
                right = i;
                while(newstr[left] == newstr[right] && right < newstr.length())
                {
                    left++;
                    right++;
                }
            }
//             z.push_back(left);
            z[i] = left;
        }
        i++;
    }
    
    int count = 0;
    for(int i = 0; i<newstr.length(); i++)
    {
        if(z[i] == m) count++;
    }
    
    return count;
}


// Another way 
int zAlgorithm(string haystack, string needle, int h, int n)
{     
    string totalStr = needle + '$' + haystack;
    int len = totalStr.length();
    vector<int> z(len);
    
    z.push_back(0);
    int l = 0;
    int r = 0;
    for(int k=1; k<len; k++){
        if(k > r){
            l=r=k;
            while(r < len && totalStr[r] == totalStr[r-l]){
                r++;
            }
            z[k] = r-l;
            r--;
        }
        else{ // k < r
            if((k+z[k-l]) <= r){
                z[k] = z[k-l];
            }
            else{
                l=k;
                while(r < len && totalStr[r] == totalStr[r-l]){
                    r++;
                }
                z[k] = r-l;
                r--;
            }
        }
    }
    
    int occurence = 0;
    for(int k=n; k<z.size(); k++){
        if(z[k] == n){
            occurence++;
        }
    }
    return occurence;
}
