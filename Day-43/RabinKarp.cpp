/*
You are given a string ‘str’ of length 'N' and a string ‘pat’ of length 'M'. Your task is to find the starting index of all the occurrences of ‘pat’ in str.
You need to return a list of integers that denote the indices from which ‘pat’ is present in ‘str’(consider 0 based indexing).
For example,
Let str= “AABAACAADAABAABA”
And pat= “AABA”
We will return the array/list [0,9,12] as we can clearly see that from indices 0 9 and 12 we have the same pattern ‘pat’ in ‘str’
Note

1. 'str' and 'pat' will consist of only uppercase English letters.
2. Two occurrences of a pattern may overlap with each other. For example, for str = "AAAA" and pat = "AA", you need to return [0,1,2] and not [0,2].

*/

#include<bits/stdc++.h>
using namespace std;
#define d 256 
vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    vector<int> ans;
    int q = 5381; 
    int M = pat.size(); 
    int N = str.size(); 
    int i, j; 
    int p = 0; // hash value for pattern 
    int t = 0; // hash value for txt 
    int h = 1; 

    // The value of h would be "pow(d, M-1)%q" 
    for (i = 0; i < M - 1; i++) 
        h = (h * d) % q; 

    // Calculate the hash value of pattern and first 
    // window of text 
    for (i = 0; i < M; i++) 
    { 
        p = (d * p + pat[i]) % q; 
        t = (d * t + str[i]) % q; 
    } 

    // Slide the pattern over text one by one 
    for (i = 0; i <= N - M; i++) 
    { 

        // Check the hash values of current window of text 
        // and pattern. If the hash values match then only 
        // check for characters on by one 
        if ( p == t ) 
        { 
            /* Check for characters one by one */
            for (j = 0; j < M; j++) 
            { 
                if (str[i+j] != pat[j]) 
                    break; 
            } 

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            if (j == M) 
                 ans.push_back(i);
//                 cout<<"Pattern found at index "<< i<<endl; 
               
        } 

        // Calculate hash value for next window of text: Remove 
        // leading digit, add trailing digit 
        if ( i < N-M ) 
        { 
            t = (d*(t - str[i]*h) + str[i+M])%q; 

            // We might get negative value of t, converting it 
            // to positive 
            if (t < 0) 
            t = (t + q); 
        } 
    } 
    return ans;
}
