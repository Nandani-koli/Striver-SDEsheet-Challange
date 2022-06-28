/*

You are given the schedule of N meetings with their start time Start[i] and end time End[i]. But you have only 1 meeting room. So, you need to tell the meeting numbers you can organize in the given room, such that the number of meetings organized is maximum.
Note:

The start time of one chosen meeting can’t be equal to the end time of the other chosen meeting. Also for the same end time, a meeting with a smaller index is preferred. 

INPUT->
6
1 3 0 5 8 5
2 4 6 7 9 9

OUTPUT_>
1 2 4 5
*/

#include <bits/stdc++.h>
using namespace std;
struct meets {
    int st;
    int ed;
    int pos;
};

bool comp(struct meets m1,struct meets m2)
{
    if(m1.ed < m2.ed)  return true;
    else if(m1.ed > m2.ed)  return false;
    else if( m1.pos < m2.pos) return true;
    
    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    struct meets meetings[n];
    for(int i = 0; i<n; i++)
    {
        meetings[i].st = start[i];
        meetings[i].ed = end[i];
        meetings[i].pos = i+1;
    }
    
    sort(meetings, meetings+n, comp);
    
    vector<int> ans;
    ans.push_back(meetings[0].pos);
    int limit = meetings[0].ed;
    for(int i = 0; i<n; i++)
    {
        if(meetings[i].st > limit)
        {
            ans.push_back(meetings[i].pos);
            limit = meetings[i].ed;
        }
    }
    
    return ans;
}

