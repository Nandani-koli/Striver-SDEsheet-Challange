/*
You have been given weights and values of ‘N’ items. You are also given a knapsack of size ‘W’.
Your task is to put the items in the knapsack such that the total value of items in the knapsack is maximum.

INPUT->
6 200
50 40 90 120 10 200             //weight
40 50 25 100 30 45              //value

OUTPUT-> 
204
*/

#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> &a, pair<int,int> &b)
{
    double vw1 = (double) a.second/a.first;
    double vw2 = (double) b.second/b.first;
    
    return vw1 > vw2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),comp);
    double ans = 0;
    for(int i = 0; i<n; i++)
    {
        if(w > items[i].first)
        {
            ans += items[i].second;
            w -= items[i].first;
        }
        else{
            double vw = (double)items[i].second/items[i].first;
            ans += vw * w;
            w = 0;
        }
    }
    
    return ans;
}