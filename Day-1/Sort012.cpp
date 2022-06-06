/* You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.

INPUT->
7
0 1 0 2 0 1 2
OUTPUT->
0 0 0 1 1 2 2 
*/
#include<iostream>
using namespace std;
void DutchNationalFlagAlgo(int *arr, int n)
{
    int low = 0,mid = 0, high = n-1;
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 2)
        {
            swap(arr[high],arr[mid]);
            high--;
        }
        else{
            mid++;
        }
    }
}
void bruteforceMethod(int *arr,int n)
{
    int z = 0,o = 0, t = 0;
   
        for(int i = 0; i<n; i++)
        {
            if(arr[i] == 0)
            {
                z++;
            }
            else if(arr[i] == 1)
            {
                o++;
            }
            else
            {
                t++;
            }
        }
        
        for(int i = 0; i < z; i++)
        {
            arr[i] = 0 ;
        }
        for(int i = z; i < z+o; i++)
        {
            arr[i] = 1;
        }
        for(int i = z+o; i< z+o+t; i++)
        {
            arr[i] = 2;
        }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    // bruteforceMethod(arr,n);
    DutchNationalFlagAlgo(arr,n);

    for(int i = 0; i< n; i++)
        cout<<arr[i]<<" ";

    cout<<endl;

}