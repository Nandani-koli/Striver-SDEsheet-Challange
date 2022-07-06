/*
Implement the Min Heap data structure.
You will be given 2 types of queries:-

0 X
Insert X in the heap.

1
Print the minimum element from the heap and remove it.
*/
#include<bits/stdc++.h>
using namespace std;
void insert(vector<int> &v,int val){
    v.push_back(val);
    int j = v.size()-1;
    
    while(j>0 && v[j]<v[(j-1)/2]){
        swap(v[j],v[(j-1)/2]);
        j = (j-1)/2;
    }
}

void remove(vector<int> &v){
    int x,i=0,j=2*i+1;
    x = v[v.size()-1];
    v[0] = x;
    v.pop_back();
    
    while(j<v.size()){
        if(v[j]>v[j+1])
            j = j+1;
        
        if(v[i]>v[j]){
            swap(v[i],v[j]);
            i = j;
            j = 2*i+1;
        }
        else{
            break;
        }
    }
    
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> v,ans;
    
    for(int i =0;i<q.size();i++){
        int n = q[i].size();
        
        if(q[i].size()==2){
            int val = q[i][1];
            insert(v,val);
        }
        else{
            ans.push_back(v[0]);
            remove(v);
        }
    }
    
    return ans;
    
}