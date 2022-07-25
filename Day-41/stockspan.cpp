/*
Ninja Coin is a famous crypto-currency in Ninja Land. Ninja has an array/list ‘PRICE’ of size ’N’ where ‘PRICE[i]’ is the price of a Ninja Coin on an ith day in INR, where 0 <= 'i' <= N-1.
The span of the Ninja Coin price on an ith day is defined as the maximum number of consecutive days (starting from the ith day and going backward) for which the price of a Ninja Coin was less than or equal to its price at ith day.
Your task is to return an array/list of size ‘N’ where the ith integer is the span of Ninja Coin price on an ith day

*/
#include<bits/stdc++.h>
using namespace std;

//Brute force TC_> O(n^2)

vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    vector<int> span;
    for(int i = 0; i<price.size(); i++)
    {
        int days = 0;
        for(int j = i ; j>= 0; j--)
        {
            if(price[i] >= price[j])
            {
                days++;
            }
            else{
                break;
            }
        }
        span.push_back(days);
    }
    return span;
}


//Better 

vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    vector<int> span;
    stack<pair<int,int>> st;
    for(auto p : price)
    {
        int days = 1;
        while(!st.empty() and st.top().first <= p)
        {
            days += st.top().second;
            st.pop();
        }
        st.push({p,days});
        span.push_back(days);
    }
    return span;
}