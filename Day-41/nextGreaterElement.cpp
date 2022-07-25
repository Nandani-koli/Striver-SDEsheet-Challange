/*
You are given an array arr of length N. You have to return a list of integers containing the NGE(next greater element) of each element of the given array. The NGE for an element X is the first greater element on the right side of X in the array. Elements for which no greater element exists, consider the NGE as -1.

INPUT->
4
1 2 4 3

OUTPUT_>
2 4 -1 -1
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreater(vector<int> &arr, int n)
{
    // Write your code here
    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (i < n)
        {
            if (st.empty() == false)
            {
                nge[i] = st.top();
            }
        }

        st.push(arr[i]);
    }

    return nge;
}