/*
You have been given a 9 X 9 2D matrix 'MATRIX' with some cells filled with digits(1 - 9), and some empty cells (denoted by 0).
You need to find whether there exists a way to fill all the empty cells with some digit(1 - 9) such that the final matrix is a valid Sudoku solution.
A Sudoku solution must satisfy all the following conditions-

1. Each of the digits 1 - 9 must occur exactly once in each row.
2. Each of the digits 1 - 9 must occur exactly once in each column.
3. Each of the digits 1 - 9 must occur exactly once in each of the 9, 3 x 3 sub-matrices of the matrix.

Note

1. There will always be a cell in the matrix which is empty.
2. The given initial matrix will always be consistent according to the rules mentioned in the problem statement.
*/

#include<bits/stdc++.h>
using namespace std;

bool check(int mat[9][9],int no,int i,int j){
    //checking row and column
    for(int k=0;k<9;k++){
        if(mat[i][k]==no || mat[k][j]==no){
            return false;
        }
    }
    //checking 3x3 subgrid
    int si=i-i%3;
    int sj=j-j%3;
    for(int i=si;i<si+3;i++){
        for(int j=sj;j<sj+3;j++){
            if(mat[i][j]==no){
                return false;
            }
        }
    }
    return true;
}
bool solveSudoku(int board[9][9], int i, int j)
{
    if(i==9) return true;
    if(j==9) return solveSudoku(board, i+1, 0);
    if(board[i][j] != 0) return solveSudoku(board, i, j+1);

    for(int c=1; c<=9; c++)
    {
        if(check(board, c, i, j)==true)
        {
            board[i][j] = c;
            if(solveSudoku(board, i, j+1)==true) return true;
            //otherwise backtrack
            board[i][j] = 0;
        }
    }
        
    return false;
}
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
     if(solveSudoku(matrix,0,0)==true){
       return true;
   }
    return  false;
}
