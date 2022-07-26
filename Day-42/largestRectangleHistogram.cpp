/*
You have been given an array/list 'HEIGHTS' of length ‘N. 'HEIGHTS' represents the histogram and each element of 'HEIGHTS' represents the height of the histogram bar. Consider that the width of each histogram is 1.
You are supposed to return the area of the largest rectangle possible in the given histogram.
*/

#include<bits/stdc++.h>
using namespace std;

//brute force approach 
int largestRectangle(vector < int > & heights) {
   // Write your code here.
     int n = heights.size();
     int maxArea = 0;
  for (int i = 0; i < n; i++) {
    int minHeight = INT_MAX;
    for (int j = i; j < n; j++) {
      minHeight = min(minHeight, heights[j]);
      maxArea = max(maxArea, minHeight * (j - i + 1));
    }
  }
  return maxArea;
 }

//better approach TC-> O(n) SC-> O(3n)
int largestRectangle(vector < int > & heights) {
   // Write your code here.
     int n = heights.size();
      stack < int > st;
      int leftsmall[n], rightsmall[n];
      for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
          st.pop();
        }
        if (st.empty())
          leftsmall[i] = 0;
        else
          leftsmall[i] = st.top() + 1;
        st.push(i);
      }
      // clear the stack to be re-used
      while (!st.empty())
        st.pop();

      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i])
          st.pop();

        if (st.empty())
          rightsmall[i] = n - 1;
        else
          rightsmall[i] = st.top() - 1;

        st.push(i);
      }
      int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
      }
      return maxA;
 }


 //optimal TC-> O(n) SC-> O(n)
int largestRectangle(vector < int > & histo) {
   // Write your code here.
  stack < int > st;
      int maxA = 0;
      int n = histo.size();
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          int height = histo[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
 }