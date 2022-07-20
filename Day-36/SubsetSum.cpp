/*
You are given an array of ‘N’ integers. You have to find the sum of all the subsets in the non-decreasing order of the given array.
For example

If N=3 and array elements are [1,2].
Following are the subset sums:
0 (by considering empty subset)
1 
2
1+2 = 3
So, subset sum are [0,1,2,3].

*/
#include<iostream>
#include<vector>
using namespace std;

void findsubsetSum(int index,int sum, vector<int> &ans, vector<int> &num,int n)
{
    if(index == n)
    {
        ans.push_back(sum);
        return ;
    }
    
    findsubsetSum(index+1,sum+num[index],ans,num,n);
    findsubsetSum(index+1,sum,ans,num,n);
    
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    int n = num.size();
    vector<int> ans;
    findsubsetSum(0,0,ans,num,n);
    
    sort(ans.begin(),ans.end());
    
    return ans;
}