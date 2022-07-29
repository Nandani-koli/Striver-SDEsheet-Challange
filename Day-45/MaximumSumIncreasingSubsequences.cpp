/*
Ninja has recently joined the gym. He decides to lift dumbbells to build muscles. The rack contains 
dumbbells with varying weights. His strategy is to pick a dumbbell randomly from the rack and after 
exercising place it back to its original position. Now for the next exercise he can only pick dumbbells 
that are heavier and positioned right to the previously used. After completing all the exercises he has 
to tell the sum of weights of all dumbbells he picked to his trainer.

In order to impress his trainer he wants this sum to be as maximum as possible. As Ninja is saving energy
for exercises, he asks you to help him choose dumbbells. Can you help Ninja to impress his trainer?

If the ‘RACK’ contains dumbbells with weights [5, 1,  2, 8], then the possible ways to choose dumbbells 
according to the given conditions are: [ 5 ], [ 1 ], [ 2 ], [ 8 ], [ 5, 8 ], [ 1, 2 ], [ 1, 2, 8 ], 
[ 2, 8 ].  Lifting dumbbells with weights [ 5, 8 ] gives the maximum sum of 13.

*/
#include<vector>
using namespace std;

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
     int dp[n] = {rack[0]}, result = rack[0];
    for(int i = 1; i<n; i++){
        dp[i] = rack[i];
        for(int j = 0; j<i; j++){
            if(rack[j]<rack[i])
                dp[i] = max(dp[i],rack[i] + dp[j]);
        }
        result = max(result,dp[i]);
    }
    return result;
}