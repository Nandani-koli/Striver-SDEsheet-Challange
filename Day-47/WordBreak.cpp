/*
You are given a list of “N” strings A. Your task is to check whether you can form a given target string
using a combination of one or more strings of A.
You can use any string of A multiple times.

A =[“coding”, ”ninjas”, “is”, “awesome”]  target = “codingninjas”
Ans = true as we use “coding” and “ninjas” to form “codingninjas”

*/


//memoization recursive solution
#include<bits/stdc++.h>
using namespace std;

int solve(string target, vector<string>& arr, unordered_map<string, int>& dp){
    int n = target.size();
    if(n==0) return 1;
    if(dp[target]!=0) return dp[target];
   
    for(int i=1;i<n+1;i++){
        string str = target.substr(0, i);
        int flag = 0;
        for(int j=0;j<arr.size();j++){
            if(str.compare(arr[j])==0){
                flag = 1;
                break;
            }
        }
        if(flag==1 and solve(target.substr(i, n-i), arr, dp)==1) return dp[target] = 1;
    }
    return dp[target] = -1;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    unordered_map<string, int> dp;
    int x = solve(target, arr, dp);
    if(x==1) return 1;
    return 0;
}

//tabulation

#include<bits/stdc++.h>
bool wordBreak(vector < string > & wordDict, int n, string & s) {
    if(wordDict.size()==0)
        {
            return false;
        }
        vector<bool>dp(s.size()+1,false);
        dp[0] = true;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])           
                {
                    string word = s.substr(j,i-j);
                    auto it = find(wordDict.begin(),wordDict.end(),word);
                    if(it!=wordDict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
}