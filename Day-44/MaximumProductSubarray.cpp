/*
You are given an array “arr'' of integers. Your task is to find the contiguous subarray within the array which has the largest product of its elements. You have to report this maximum product.

An array c is a subarray of array d if c can be obtained from d by deletion of several elements from the beginning and several elements from the end.

For e.g.- The non-empty subarrays of an array [1,2,3] will be- [1],[2],[3],[1,2],[2,3],[1,2,3]. 

If arr = {-3,4,5}.
All the possible non-empty contiguous subarrays of “arr” are {-3}, {4}, {5}, {-3,4}, {4,5} and {-3,4,5}.
The product of these subarrays are -3, 4, 5, -12, 20 and -60 respectively.
The maximum product is 20. Hence, the answer is 20.

 */
#include<vector>
using namespace std;

int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
    int ans = arr[0];
    int ma = ans;
    int mi = ans;
    
    for(int i = 1; i<n; i++)
    {
        if(arr[i] < 0)
        {
            swap(ma,mi);
        }
        ma = max(arr[i], ma * arr[i]);
        mi = min(arr[i], mi * arr[i]);
        ans = max(ans,ma);
    }
    
    return ans;
}
