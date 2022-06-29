/*
You are given N activities with their start time Start[] and finish time Finish[]. You need to tell the maximum number of activities a single person can perform.
Note: A person can only work on a single activity at a time. The start time of one activity can coincide with the end time of another.


INPUT->
4
1 6 2 4             //start time
2 7 5 8             //finish time

OUTPUT->
3

*/
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> &a, pair<int,int> &b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> act;
    int n = start.size();
    for(int i =0; i<n; i++)  
    {
        act.push_back({start[i],finish[i]});
    }
    
    sort(act.begin(),act.end(),comp);
    
    int ans = 1;
    int ed = act[0].second;
    
    for(int i =1; i<act.size(); i++)
    {
        if(act[i].first >= ed)
        {
            ans++;
            ed = act[i].second;
        }
    }
    
    return ans;
}
int main()
{
    int n ;
    cin>>n;
    vector<int> start;
    vector<int> end;

    for(int i =0; i<n; i++)
    {
        int x;
        cin>>x;
        start.push_back(x);
       
    }

    for(int i =0; i<n; i++)
    {
        int x;
        cin>>x;
        end.push_back(x);
     
    }
   int ans = maximumActivities(start,end);
   cout<<ans<<endl;
}
