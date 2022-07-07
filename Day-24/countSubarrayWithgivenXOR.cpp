/*
Given an array of integers ‘ARR’ and an integer ‘X’, you are supposed to find the number of subarrays of 'ARR' which have bitwise XOR of the elements equal to 'X'.
Note:

An array ‘B’ is a subarray of an array ‘A’ if ‘B’ that can be obtained by deletion of, several elements(possibly none) from the start of ‘A’ and several elements(possibly none) from the end of ‘A’. 

INPUT->
5 8
5 3 8 3 10

OUTPUT->
2
*/

//brute force
#include <bits/stdc++.h> 
using namespace std;
int subarraysXor(vector<int> &A, int B)
{
    //    Write your code here.
    long long c=0;
    for(int i=0;i<A.size();i++){
        int current_xor = 0;
        for(int j=i;j<A.size();j++){
            current_xor^=A[j];
            if(current_xor==B) c++;
        }
    }
    return c;
}


//optimized 

int subarraysXor(vector<int> &A, int B)
{
    //    Write your code here.
    unordered_map<int,int>visited;
    int cpx = 0;
    long long c=0;
    for(int i=0;i<A.size();i++){
        cpx^=A[i];
        if(cpx==B) c++;
        int h = cpx^B;
        if(visited.find(h)!=visited.end()){
            c=c+visited[h];
        }
        visited[cpx]++;
    }
    return c;
}