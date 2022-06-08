/*
INPUT->
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

OUTPUT->
5 1 2 3 
9 10 6 4 
13 11 7 8 
14 15 16 12 
*/
#include <bits/stdc++.h> 
using namespace std; 
void rotateBy90Degree(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i =0; i<n; i++)
        {
            for(int j =i; j<m; j++)
            {
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        for(int i = 0; i<n; i++)
        {
        reverse(matrix[i].begin(),matrix[i].end());
        }
    } 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int row = 0, col = 0; 
    int prev, curr; 
    int lastRow= n;
    int lastCol= m;
    while (row < lastRow && col < lastCol) 

    {  
        if (row + 1 == lastRow || col + 1 == lastCol)  break;   

        prev = mat[row + 1][col]; 
        for (int i = col; i < lastCol; i++) 
        { 
            curr = mat[row][i]; 
            mat[row][i] = prev; 
            prev = curr; 
        } 
        row++; 
        for (int i = row; i < lastRow; i++) 
        { 
            curr = mat[i][lastCol-1]; 
            mat[i][lastCol-1] = prev; 
            prev = curr; 
        } 
        lastCol--;   
        if (row < lastRow) 
        { 
            for (int i = lastCol-1; i >= col; i--) 
            { 
                curr = mat[lastRow-1][i]; 
                mat[lastRow-1][i] = prev; 
                prev = curr; 
            } 
        } 
        lastRow--; 
        if (col < lastCol) 
        { 
            for (int i = lastRow-1; i >= row; i--) 
            { 
                curr = mat[i][col]; 
                mat[i][col] = prev; 
                prev = curr; 
            } 
        } 
        col++; 
    }
}

int main() 
{ 
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int> (m));
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<m; j++)
        {
            cin>>mat[i][j];
        }
    }

	// rotateMatrix(mat,n,m);
    rotateBy90Degree(mat);

    for(int i =0; i<mat.size(); i++)
    {
        for(int j =0; j<mat[0].size(); j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0; 
} 
