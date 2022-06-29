

#include<iostream>
using namespace std;
int findMinimumCoins(int amount) 
{
    int ans = 0;
    int arr[] = {1,2,5,10,20,50,100,500,1000};
    int n = 9;
    for(int i =n-1; i >= 0; i--)
        {
         while(amount >= arr[i])
            {
                amount -= arr[i];
                ans++;
            }
        }
    
    return ans;
}

int main()
{
    int a;
    cin>>a;
    int res = findMinimumCoins(a);
    cout<<res<<endl;
}