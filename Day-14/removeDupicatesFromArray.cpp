#include<iostream>
#include<set>
using namespace std;

//optimized Approach TC->O(n) SC-> O(1)
int removeDuplicates(int arr[], int n) {

    int i = 0;
    for(int j = 1; j<n; j++)
    {
        if(arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}

//Brute Force TC-> O(n*log(n))+O(n) SC->O(n)
int removeduplicatess(int arr[], int n)
{
    set<int> st;
    for(int i = 0; i<n; i++)
    {
        st.insert(arr[i]);
    }
    int k = st.size();
    int j = 0;
    for(int x : st)
    {
        arr[j++] = x;
    }

    return k;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++) cin>>arr[i];

    // int length = removeduplicatess(arr, n);

    int length = removeDuplicates(arr,n);


    for(int i = 0; i<length; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}