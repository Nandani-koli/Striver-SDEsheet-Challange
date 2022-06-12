/*
You are given an array/list 'ARR' of integers of length ‘N’. You are supposed to find all the elements that occur strictly more than floor(N/3) times in the given array/list.
INPUT->
3 2 2 1 5 2 3

OUTPUT->
2
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElementII(vector<int> &arr)
{
    int sz = arr.size();
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
    for (i = 0; i < sz; i++)
    {
        if (arr[i] == num1)
            count1++;
        else if (arr[i] == num2)
            count2++;
        else if (count1 == 0)
        {
            num1 = arr[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            num2 = arr[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    vector<int> ans;
    count1 = count2 = 0;
    for (i = 0; i < sz; i++)
    {
        if (arr[i] == num1)
            count1++;
        else if (arr[i] == num2)
            count2++;
    }
    if (count1 > sz / 3)
        ans.push_back(num1);
    if (count2 > sz / 3)
        ans.push_back(num2);
    return ans;
}

int main()
{
    vector<int> arr = {3,2 ,2 ,1, 5, 2, 3};
    vector<int> ans;
    ans = majorityElementII(arr);
    for(int i =0; i< ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}