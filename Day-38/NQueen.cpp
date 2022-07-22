/*
You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way to place 'N' queens such that no queen can attack any other queen on the chessboard.
A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
*/


#include <bits/stdc++.h>
using namespace std;

void addsolution(vector<vector<int>> &board,vector<vector<int>> &ans, int n)
{
     vector<int> temp;
        for (auto it : board)
        {
            for (int i : it)
            {
                temp.push_back(i);
            }
        }
        ans.push_back(temp);
}
void solve(int col, vector<vector<int>> &board, int n, vector<int> &leftrow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal,vector<vector<int>> &ans)
{
    if (col == n)
    {
        addsolution(board,ans,n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
        {
            board[row][col] = 1;

            leftrow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;

            solve(col + 1, board, n, leftrow, upperDiagonal, lowerDiagonal,ans);

            // backtrack
            board[row][col] = 0;
            leftrow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));

    vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, n, leftrow, upperDiagonal, lowerDiagonal,ans);

    return ans;
}