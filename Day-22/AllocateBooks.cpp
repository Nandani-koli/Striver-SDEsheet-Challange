/*
Ayush is studying for ninjatest which will be held after 'N' days, And to score good marks he has to study 'M' chapters and the ith chapter requires TIME[i] seconds to study. The day in Ayush’s world has 100^100 seconds. There are some rules that are followed by Ayush while studying.
1. He reads the chapter in a sequential order, i.e. he studies i+1th chapter only after he studies ith chapter.
2. If he starts some chapter on a particular day he completes it that day itself.
3. He wants to distribute his workload over 'N' days, so he wants to minimize the maximum amount of time he studies in a day.
Your task is to find out the minimal value of the maximum amount of time for which Ayush studies in a day, in order to complete all the 'M' chapters in no more than 'N' days.

INPUT->
3 5
1 2 2 3 1

OUTPUT-> 4

Explanation :-

The ayush will read the chapter as follows,
Day 1 : 1 , 2         Time required : 3
Day 2 : 3             Time required : 2
Day 3 : 4 , 5         Time required : 4
So the maximum time in a day is 4.

*/

#include<bits/stdc++.h>
using namespace std;
bool isPossible(long long int n, long long int m, long long int mid, vector<int> time)
{
    int days = 1;
    long long int chapters = 0;
    for (long long int i = 0; i < m; i++)
    {
        if (time[i] + chapters <= mid)
        {
            chapters = chapters + time[i];
        }
        else
        {
            days++;
            if (days > n || time[i] > mid) // n is no. of given days
            {
                return false;
           }
            chapters = time[i];
        }
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    long long s = time[0];
    long long sum = 0; // m is size
    long long ans;
    for (int i = 0; i < m; i++)
    {
        sum = sum + time[i];
    }
    long long e = sum;
    long long mid = (s + e) / 2;
    while (s <= e)
    {
        if (isPossible(n, m, mid, time))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = (s + e) / 2;
    }
    return ans;
}
