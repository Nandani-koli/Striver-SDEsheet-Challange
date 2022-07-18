/*
You will be given a stream of numbers, and you need to find the kth largest number in the stream at any given time.
As the stream of numbers can not be given during compile time, so you need to design a data structure which can accept infinite numbers and can return the kth largest number at any given time.
The stream of numbers is nothing but a large collection of numbers from which integers are read at runtime, such as the user will never know the upper limit on the number of integers which will be read.
The implemented data structure must support the following operations:

1. add(DATA) :
   This function should take one argument of type integer 
   and store it in its pool.
2. int getKthLargest() :
   This function should return the kth largest number from 
   the current pool of integers.
*/

#include<bits/stdc++.h>
using namespace std;

class Kthlargest {
public:
    priority_queue<int,vector<int>, greater<int>> pq;
    int gk;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
        gk = k;
        for(auto x : arr)
        {
            if(pq.size() < k)
                pq.push(x);
            else if(pq.size() == k && x >= pq.top())
                pq.push(x);
            
            if(pq.size() > k)
                pq.pop();
        }
    }

    void add(int num) {
        // Write your code here.
        if(pq.size() < gk)
            pq.push(num);
        else if(pq.size() == gk && num >= pq.top())
            pq.push(num);
            
        if(pq.size() > gk)
            pq.pop();
    }

    int getKthLargest() {
       // Write your code here.
        return pq.top();
    }

};