//You are given an array/list 'ARR' of ‘N’ integers and an integer value ‘TARGET’. You need to check whether there exist four numbers (ARR[i], ARR[j], ARR[k], ARR[l]) such that (0 <= i < j < k < l < N) and ARR[i] + ARR[j] + ARR[k] + ARR[l] = 'TARGET'.

#include <bits/stdc++.h>
using namespace std;
string fourSum(vector<int> arr, int target, int n)
{

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n-3; i++)
    {
        if (i == 0 || (i > 0 && arr[i] != arr[i - 1]))
        {
            int sum1 = target - arr[i];
            for (int j = i + 1; j < n-2; j++)
            {
                if (j == 1 || (j > 1 && arr[j] != arr[j - 1]))
                {
                    int low = j + 1, high = n - 1, sum = sum1 - arr[j];
                    while (low < high)
                    {
                        if (arr[low] + arr[high] == sum)
                        {
                            return "Yes";

                            // while(low<high && arr[low] == arr[low+1])  low++;
                            // while(low<high && arr[high] == arr[high-1])  high--;

                            // low++ , high--;
                        }

                        else if (arr[low] + arr[high] < sum)
                            low++;
                        else
                            high--;
                    }
                }
            }
        }
    }

    return "No";
}
int main()
{
    vector <int> arr ;
    arr = {1,5,6,3};

   cout<< fourSum(arr,13,4);
}