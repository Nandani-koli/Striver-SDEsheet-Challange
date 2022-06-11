//Binary search in 2D array
//INPUT->
// 3 4

// 5 6 7 8
// 13 14 15 16
// 23 24 25 26

// 14

//output->
// 1

#include <bits/stdc++.h> 
#include <vector>
using namespace std;
bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    int low = 0, high = (m*n)-1;
    while(low<= high)
    {
        int mid = (low+high)/2;
        if(mat[mid/n][mid%n] == target)
        {
            return true;
        }
        else if(mat[mid/n][mid%n] < target)
        {
            low = mid + 1;
        }
        else if(mat[mid/n][mid%n] > target)
        {
            high = mid -1;
        }
    }
    
    return false;
}

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> arr(m, vector<int> (n));
    for(int i = 0; i< m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }
    int target;
    cin>>target;

    cout<<findTargetInMatrix(arr,m,n,target)<<endl;
}