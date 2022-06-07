/* 
You are given an array/list 'prices' where the elements of the array represent the prices of the stock as they were yesterday and indices of the array represent minutes. Your task is to find and return the maximum profit you can make by buying and selling the stock. You can buy and sell the stock only once.
Note: You can’t sell without buying first.
INPUT->
4
1 2 3 4
OUTPUT->
3

INPUT->
4
2 2 2 2
OUTPUT->
0
*/
#include <bits/stdc++.h> 
using namespace std;
int maxProfitOptimized(vector<int> & prices)
{
    int maxprofit = 0;
    int minele = 1e9;
    for(int i = 0; i<prices.size(); i++)
    {
        minele = min(minele, prices[i]);
        maxprofit = max(maxprofit, prices[i] - minele);
    }
    return maxprofit;
}
int maximumProfit(vector<int> &prices)
{
    int maxProfit = INT_MIN;
 
    for(int i = 0; i<prices.size(); i++)
    {
        for(int j = i+1; j < prices.size(); j++)
        {
        int sum = prices[j] - prices[i];
        maxProfit = max(sum,maxProfit);           
        }
    }
    return maxProfit;
}
int main()
{
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i= 0; i<n; i++)
    {
        cin>>prices[i];
    }

    // cout<<maximumProfit(prices)<<endl;
    cout<<maxProfitOptimized(prices)<<endl;
}