#include <bits/stdc++.h> 
using namespace std;

int Solution1(vector<int> &arr, int n){
    for(int i = 0; i< n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr[i] == arr[i+1])
            {
            return arr[i];
            }
        }
    }
}
int Solution2(vector<int> &arr, int n){
    sort(arr.begin(),arr.end());
    for(int i = 0; i< n; i++)
    {
        if(arr[i] == arr[i+1])
        {
            return arr[i];
        }
    }
}

int Solution3(vector<int> &arr, int n){
    int freq[n+1] = {0};
    for(int i = 0; i< n; i++)
    {
        if(freq[arr[i]] == 0)
        {
            freq[arr[i]]++;
        }
        else{
            return arr[i];
        }
    }
}

int main()
{
    int n;
    vector<int> arr(n);
    for(int i =0; i<n; i++)
        cin>>arr[i];

   cout<< Solution2(arr,n) <<endl;

    

}