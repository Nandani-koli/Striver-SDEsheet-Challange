 
/*
Que:- 
You are given N number of intervals, where each interval contains two integers denoting the start time and the end time for the interval.
The task is to merge all the overlapping intervals and return the list of merged intervals sorted by increasing order of their start time.
Two intervals [A,B] and [C,D] are said to be overlapping with each other if there is at least one integer that is covered by both of them.

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

INPUT->
{{1, 4}, {3, 5}, {6, 8}, {8, 10}, {9, 12}}
OUTPUT->
1 5
6 12
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> mergeInterval;
    sort(intervals.begin(),intervals.end());
    vector<int> temp = intervals[0];
    
    for(auto it : intervals)
    {
        if(it[0] <= temp[1])
        {
            temp[1] = max(it[1],temp[1]);
        }
        else{
            mergeInterval.push_back(temp);
            temp = it;
        }
    }
    
    mergeInterval.push_back(temp);
    
    return mergeInterval;
}
int main()
{

    vector < vector < int >> arr;
    arr = {{1, 4}, {3, 5}, {6, 8}, {8, 10}, {9, 12}};
    vector < vector < int >> ans = mergeIntervals(arr);

  for (auto it: ans) {
    cout << it[0] << " " << it[1] << "\n";
  }

}
