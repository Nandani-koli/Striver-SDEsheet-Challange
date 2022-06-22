#include <bits/stdc++.h>
using namespace std;

// brute force Approach TC:- O(n^3)
vector<vector<int>> threeSum(vector<int> &nums, int K)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int i, j, k;
    for (i = 0; i < nums.size() - 2; i++)
    {
        for (j = i + 1; j < nums.size() - 1; j++)
        {
            for (k = j + 1; k < nums.size(); k++)
            {
                temp.clear();
                if (nums[i] + nums[j] + nums[k] == K)
                {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                }
                sort(temp.begin(), temp.end());
                if (!(count(ans.begin(), ans.end(), temp)))
                    ans.push_back(temp);
            }
        }
    }

    return ans;
}

// optimized Approach using 2 pointer approach TC :- O(n^2)
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{

    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++)
    {
        if (i == 0 || (i > 0 && arr[i] != arr[i - 1]))
        {
            int low = i + 1, high = n - 1, sum = K - arr[i];
            while (low < high)
            {
                if (arr[low] + arr[high] == sum)
                {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[low]);
                    temp.push_back(arr[high]);

                    ans.push_back(temp);

                    while (low < high && arr[low] == arr[low + 1])
                        low++;
                    while (low < high && arr[high] == arr[high - 1])
                        high--;

                    low++, high--;
                }

                else if (arr[low] + arr[high] < sum)
                    low++;
                else
                    high--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr{10, 5, 5, 5, 2};
    vector<vector<int>> ans;
    int K = 12;
    ans = threeSum(arr, K);

    cout << "The triplets are as follows: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}