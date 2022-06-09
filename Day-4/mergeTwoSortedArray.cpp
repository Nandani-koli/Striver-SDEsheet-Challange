#include <bits/stdc++.h>
#include <vector>
using namespace std;
//Brute force Approach
vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    vector<int> arr3;

    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            arr3.push_back(arr1[i++]);
        }
        else
        {
            arr3.push_back(arr2[j++]);
        }
    }
    while (i < m)
    {
        arr3.push_back(arr1[i++]);
    }
    while (j < n)
    {
        arr3.push_back(arr2[j++]);
    }
    return arr3;
}

//optimized Space complexity approach
vector<int> SortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    int i, j = 0;

    for (i = 0; i < n; i++)
    {
        if (arr1[i] > arr2[0])
        {
            swap(arr1[i], arr2[0]);
            sort(arr2.begin(), arr2.end());
        }
    }
    while (i < arr1.size())
    {
        arr1[i++] = arr2[j++];
    }
    return arr1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n + m, 0);
    vector<int> arr2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    // SortedArrays(arr1, arr2, m, n);
    vector<int> ans = ninjaAndSortedArrays(arr1,arr2,m,n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
