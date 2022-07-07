/*
Ninja loves playing with numbers. So his friend gives him an array on his birthday. The array consists of positive and negative integers. Now Ninja is interested in finding the length of the longest subarray whose sum is zero.
*/

//brute force 
#include <bits/stdc++.h> 
using namespace std;
int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    int  maxsum = 0;
    for(int i = 0; i < arr.size(); ++i){
        int sum = 0;
        for(int j = i; j < arr.size(); ++j){
            sum += arr[j];
            if(sum == 0){
                maxsum = max(maxsum, j-i+1);
            }
        }
    }
    return maxsum;

}

//optimized 

#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    unordered_map<int,int> map;
    int ans = 0, sum =0;
    for(int i =0; i<arr.size(); i++)
    {
        sum += arr[i];
        if(sum == 0)
        {
            ans = i + 1;
        }
        else{
            if(map.find(sum) != map.end())
            {
                ans = max(ans, i - map[sum]);
            }
            else{
                map[sum] = i;
            }
        }
    }
    return ans;
}