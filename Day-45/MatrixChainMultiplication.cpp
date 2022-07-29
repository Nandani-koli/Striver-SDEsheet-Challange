/*
Given a chain of matrices A1, A2, A3,.....An. Your task is to find out the minimum cost to multiply 
these matrices. The cost of matrix multiplication is defined as the number of scalar multiplications.
 A Chain of matrices A1, A2, A3,.....An is represented by a sequence of numbers in an array ‘arr’ where 
 the dimension of 1st matrix is equal to arr[0] * arr[1] , 2nd matrix is arr[1] * arr[2], and so on.

For arr[ ] = { 10, 20, 30, 40}, matrix A1 = [10 * 20], A2 = [20 * 30], A3 = [30 * 40]

Scalar multiplication of matrix with dimension 10 * 20 is equal to 200.

*/

//Tabulation Approach
#include<vector>
using namespace std;

int matrixMultiplication(vector<int> &arr, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=1;i<n;i++) dp[i][i]=0;
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            int mini=1e9;
             for(int k=i;k<j;k++){
                    int cost=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    mini=min(cost,mini);
                }
                dp[i][j]=mini;
        }
    }
    return dp[1][n-1];
}


///Memoization Approach 

int f(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
    if(i==j) return 0;
    int mini=1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i;k<j;k++){
        int cost=arr[i-1]*arr[k]*arr[j]+f(i,k,arr,dp)+f(k+1,j,arr,dp);
        mini=min(cost,mini);
    }
    return dp[i][j]=mini;
}
int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return f(1,n-1,arr,dp);
    
}

//Tabulation

