/*
Given an ‘N’ x ‘M’ integer matrix, if an element is 0, set its entire row and column to 0's, and return the matrix. In particular, your task is to modify it in such a way that if a cell has a value 0 (matrix[i][j] == 0), then all the cells of the ith row and jth column should be changed to 0.
If the given grid is this:
[7, 19, 3]
[4, 21, 0]

Then the modified grid will be:
[7, 19, 0]
[0, 0,  0]
*/
#include<iostream>
#include<vector>
using namespace std;
void optimizedMethod(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> rowvector(row,-1);
    vector<int> colvector(col,-1);
    
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j< col; j++)
        {
            if(matrix[i][j] == 0)
            {
                rowvector[i] = 0;
                colvector[j] = 0;
            }
        }
    }
    
    for(int i = 0; i<row; i++)
    {
        for(int j = 0; j< col; j++)
        {
            if(rowvector[i] == 0 || colvector[j] == 0)
            {
                matrix[i][j] =0;
            }
        }
    }
}

void bruteforceMethod(vector<vector<int>> &matrix, int n,int m)
{

	for(int i =0; i<n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(matrix[i][j] == 0)
            {
               int index = i - 1;
               while(index >= 0)
               {
                   if(matrix[index][j] != 0)
                       {matrix[index][j] = -1;}

                index--;
               }

                index = i + 1;
               while(index < n)
               {
                   if(matrix[index][j] != 0)
                      { matrix[index][j] = -1;}

                index++;
               }

                index = j - 1;
               while(index >= 0)
               {
                   if(matrix[i][index] != 0)
                       {matrix[i][index] = -1;}
                index--;
               }

               index = j + 1;
               while(index < m)
               {
                   if(matrix[i][index] != 0)
                       {matrix[i][index] = -1;}
                index++;
               }
            }
        }
    }

    for(int i = 0; i<n; i++)
    {
        for(int j =0; j<m; j++)
        {
            if(matrix[i][j] < 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
 int main()
 {
     int n,m;
     cin>>n>>m;

     vector<vector<int>> matrix( n , vector<int> (m)); 
     for(int i = 0; i<n; i++)
     {
        for(int j = 0; j<m; j++)
        {
            cin>>matrix[i][j];
        }
     }
    
    // bruteforceMethod(matrix,n,m);
    optimizedMethod(matrix);

     for(int i = 0; i<matrix.size(); i++)
     {
        for(int j = 0; j<matrix[0].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
     }
 }

