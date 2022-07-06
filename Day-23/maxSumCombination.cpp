/*
You are given two arrays/lists ‘A’ and ‘B’ of size ‘N’ each. You are also given an integer ‘K’. You have to find the ‘K’ maximum and valid sum combinations from all the possible sum combinations of the arrays/lists ‘A’ and ‘B’.
Sum combination is made by adding one element from array ‘A’ and another element from array ‘B’.
For example :

A : [1, 3] 
B : [4, 2] 
K : 2
The possible sum combinations can be 5(3 + 2), 7(3 + 4), 3(1 + 2), 5(1 + 4). The 2 maximum sum combinations are 7 and 5. 
*/

#include<bits/stdc++.h>
using namespace std;

//method 1
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
   priority_queue<int> pq;
   for(int i = 0; i<n; i++)
   {
     for(int j = 0; j<n; j++)
     {
         int sum = a[i] + b[j];
         pq.push(sum);
     }
   }
   vector<int> ans;
   while(k--)
   {
       ans.push_back(pq.top());
       pq.pop();
   }
  
   return ans;
}

//method 2

vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int n, int C){

   vector<int> ans;
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    priority_queue<pair<int, pair<int, int>>> pq; // A[i]+B[j], <i, j>
    set<pair<int, int>> vis; // i, j
    
    pq.push({A[0]+B[0], {0 ,0}});
    vis.insert({0, 0});
    
    for(int i=0; i<C; ++i) {
        auto p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        
        if(p.second.first+1 < n && vis.find({p.second.first+1, p.second.second}) == vis.end()) {
            vis.insert({p.second.first+1, p.second.second});
            int x = A[p.second.first+1] + B[p.second.second];
            pq.push({x, {p.second.first+1, p.second.second}});
        }
        if(p.second.second+1 < n && vis.find({p.second.first, p.second.second+1}) == vis.end()) {
            vis.insert({p.second.first, p.second.second+1});
            int x = A[p.second.first] + B[p.second.second+1];
            pq.push({x, {p.second.first, p.second.second+1}});
        }
    }
    
    return ans;
}