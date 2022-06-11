/*
You are given an array of size ‘N’. The elements of the array are in the range from 1 to ‘N’.
Ideally, the array should contain elements from 1 to ‘N’. But due to some miscalculations, there is a number R in the range [1, N] which appears in the array twice and another number M in the range [1, N] which is missing from the array.
Your task is to find the missing number (M) and the repeating number (R).

INPUT->
6
3 1 2 3 4 6

OUTPUT->
Missing Number = 5
Repeating Number = 3
*/

#include <bits/stdc++.h> 
using namespace std;

//TC = 0(n) SC = O(n)
pair<int,int> Approach1(vector<int> &arr, int n)
{
	// Write your code here 
    pair<int,int> output;
	vector<int> count(n+1,0);
    
    for(int i =0; i<n; i++)
    {
        count[arr[i]]++;
    }
    
    for(int i =0; i<=arr.size(); i++)
    {
        if(count[i] == 0)
        {
            output.first = i;
        }
        else if(count[i] > 1)
        {
            output.second = i;
        }
    }
    
    return output;
}
//TC = 0(n) SC = O(1)
pair<int,int> Approach2(vector<int> &arr, int n)
{
    long long int S = (n * (n+1) ) /2;
    long long int P = (n * (n +1) *(2*n +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<arr.size(); i++){
       S -= (long long int)arr[i];
       P -= (long long int)arr[i]*(long long int)arr[i];
    }
     
    missingNumber = (S + P/S)/2;
    repeating = missingNumber - S;

    pair<int,int> ans;
    ans.first = missingNumber;
    ans.second = repeating;

    return ans;
}


int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i =0; i<n; i++)
    {
        cin>>arr[i];
    }

    pair<int,int> ans;
    ans = Approach1(arr,n);
    // ans = Approach2(arr,n);

    cout<<"Missing Number = "<<ans.first<<endl;
    cout<<"Repeating Number = "<<ans.second<<endl;

}