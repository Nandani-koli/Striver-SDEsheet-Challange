/*
You are given an integer N. Your task is to return a 2-D ArrayList containing the pascal’s triangle till the row N.
A Pascal's triangle is a triangular array constructed by summing adjacent elements in preceding rows. Pascal's triangle contains the values of the binomial coefficient.
For example in the figure below.

     1
    1 1
   1 2 1
  1 3 3 1
 1 4 6 4 1
 */
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> printPascal(int n)
{
    vector<vector<int>> pascal(n);
    for (int i = 0; i < n; ++i)
    {
        pascal[i].resize(i + 1);
        pascal[i][0] = pascal[i][i] = 1;
        for (int j = 1; j < i; ++j)
        {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }
    return pascal;
}
int main()
{

    int n;
    cout << "Enter no of rows:- ";
    cin >> n;

    vector<vector<int>> ans;
    ans = printPascal(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
