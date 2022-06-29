/*
You are given a N x 2 2-D array 'Jobs' of 'N' jobs where Jobs[i][0] denote the deadline of i-th job and Jobs[i][1] denotes the profit associated with i-th job.
You will make a certain profit if you complete the job within the deadline associated with it. Each job takes 1 unit of time to be completed, and you can schedule only one job at a particular time.
Your task is to find out the maximum profit that you can make.

INPUT->
5
2 25
4 40
1 5
3 50
5 60

OUTPUT->
180
*/
#include<bits/stdc++.h>
using namespace std;
bool comp(vector<int> &v1, vector<int> &v2)
{
    return v1[1] > v2[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(),jobs.end(),comp);
    int n = jobs.size();
   int maxdead = 0;
    for(int i = 0; i<n; i++)
    {
        maxdead = max(maxdead,jobs[i][0]);
    }
    
    int dead[maxdead];
    for(int i = 0; i<maxdead; i++)  dead[i] = 0;
    
    int ansp = 0;
    for(int i = 0;i<n; i++)
    {
        for(int j = jobs[i][0] - 1 ; j >= 0; j--)
        {
            if(dead[j] == 0)
            {
                dead[j] = 1;
                ansp += jobs[i][1];
                break;
            }
        }
    }
    
    return ansp;
}

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> jobs(m, vector<int> (n));
    for(int i = 0; i< m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin>>jobs[i][j];
        }
    }

    int profit = jobScheduling(jobs);
    cout<<profit<<endl;
}